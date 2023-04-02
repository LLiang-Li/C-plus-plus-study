#include"image_analysis.h"

namespace lige
{
  void Fft(char** argv)
  {
    cv::Mat A = cv::imread(argv[1], 0);

    if(A.empty())
      return ;
    cv::Size patch_size(100, 100);
    cv::Point top_left(A.cols/2, A.rows/2);
    cv::Rect roi(top_left.x, top_left.y, patch_size.width, patch_size.height);

    cv::Mat B = A(roi);
    int dft_M = cv::getOptimalDFTSize(A.rows + B.rows - 1);
    int dft_N = cv::getOptimalDFTSize(A.cols + B.cols - 1);

    cv::Mat dft_A = cv::Mat::zeros(dft_M, dft_N, CV_32F);
    cv::Mat dft_B = cv::Mat::zeros(dft_M, dft_N, CV_32F);

    cv::Mat dtf_A_part = dft_A(cv::Rect(0, 0, A.cols, A.rows));
    cv::Mat dtf_B_part = dft_B(cv::Rect(0, 0, B.cols, B.rows));

    A.convertTo(dtf_A_part, dtf_A_part.type(), 1 , -cv::mean(A)[0]);
    B.convertTo(dtf_A_part, dtf_B_part.type(), 1 , -cv::mean(B)[0]);

    cv::dft(dft_A, dft_A, 0, A.rows);
    cv::dft(dft_B, dft_B, 0, B.rows);

    cv::mulSpectrums(dft_A, dft_B, dft_A, 0, true);
    cv::idft(dft_A, dft_A, cv::DFT_SCALE, A.rows + B.rows - 1);
    
    cv::Mat corr = dft_A(cv::Rect(0, 0, A.cols + B.cols -1, A.rows + B.rows - 1));

    LOG("cols = %d, rows = %d, type = %x, depth = %d\n", corr.cols, corr.rows, corr.type(), corr.channels());
    LOG("%d, %x", CV_MAT_TYPE_MASK, CV_MAT_TYPE_MASK);
    

    cv::normalize(corr, corr, 0, 1, cv::NORM_MINMAX, corr.type());

    cv::pow(corr, 3.0, corr);
    for(int i = 0; i <  corr.cols; i++)
    {
      LOG("\n");
      for(int j = 0; j < corr.rows; j++)
        LOG("%f", corr.at<float>(j, i));
    }
    cv::imshow("ori", A);
    cv::imshow("Corr", corr);
    cv::waitKey(0);
  }

  //make; .\lige.exe C:\Users\jetson\Pictures\a.PNG 200 100 3 
  void Canny(char** argv)
  {
    cv::Mat img = cv::imread(argv[1], 0);
    cv::Mat edges;
    cv::Canny(img, edges, atof(argv[2]), atof(argv[3]), atof(argv[4]));

    std::unordered_map<int, int> image_counter;
    for(int i = 0; i < img.rows; i++)
    {
      for(int j = 0; j < img.cols; j++)
        image_counter[img.at<unsigned char>(i,j)]++;
    }

    for(auto i : image_counter)
      LOG("%d : %d\n", i.first, i.second);

    cv::imshow("imge", img);
    cv::imshow("edge", edges);

    cv::waitKey(0);

  }

  void Hough(char** argv)
  {
    cv::Mat img = cv::imread(argv[1], 0);
    cv::imshow("image", img);
    
    cv::Mat lines;
    cv::HoughLines(img, lines, atof(argv[2]), atof(argv[3]), atoi(argv[4]));

    LOG("rows = %d, cols = %d, type = %d, channel = %d\n", lines.rows, lines.cols, lines.type(), lines.channels());

    // for(int i = 0; i < lines.rows; i++)
    //   LOG("%f, %f\n", lines.at<cv::Vec2f>(i)[0], lines.at<cv::Vec2f>(i)[0]);
    cv::Mat lineP, edges;
    cv::Canny(img, edges, 200, 100, 3);
    cv::imshow("edge", edges);
    cv::HoughLinesP(edges, lineP, atof(argv[2]), atof(argv[3]), atoi(argv[4]));
    LOG("rows = %d, cols = %d, type = %d, channel = %d\n", lineP.rows, lineP.cols, lines.type(), lineP.channels());
    for(int i = 0; i < lineP.rows; i++)
    {
      LOG("%f, %f, %f, %f\n",lineP.at<cv::Vec4f>(i)[0], lineP.at<cv::Vec4f>(i)[1], lineP.at<cv::Vec4f>(i)[2], lineP.at<cv::Vec4f>(i)[3]);
      cv::line(edges, cv::Point(lineP.at<cv::Vec4f>(i)[0], lineP.at<cv::Vec4f>(i)[1]),
                cv::Point(lineP.at<cv::Vec4f>(i)[2], lineP.at<cv::Vec4f>(i)[3]), cv::Scalar(0));
    }

    cv::imshow("lins", edges);

    

    cv::waitKey(0); 
  }
} // namespace lige
