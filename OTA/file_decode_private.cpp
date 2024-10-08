#include "file_decode_private.hpp"
#include <iostream>

#define HEX_EXTENDED_INDEX_0 7U
#define HEX_EXTENDED_INDEX_1 0U

#define HEX_EXTENDED_TYPE_CODE 2U

//Here are index for calculating real addr when extended addr is existed
#define HEX_CAN_ADDR_0 2U
#define HEX_CAN_ADDR_1 3U
#define HEX_CAN_ADDR_2 4U
#define HEX_CAN_ADDR_3 5U

namespace ota
{
  #define CLEAR_STREAM() \
          this->str_to_dec_.str("");\
          this->str_to_dec_.clear()

  #define STR_TO_DEC(string) \
          this->str_to_dec_.str("");\
          this->str_to_dec_.clear();\
          this->str_to_dec_.str(string);\
          this->str_to_dec_ >> std::hex >> this-> dec_

  #define STR_TO_VECOTR() \
          for(; i < content.length();){\
            if(line_8_elements.size()>7){\
              this->decode_result_.emplace_back(line_8_elements);\
              line_8_elements.clear();\
            }\
            STR_TO_DEC(content.substr(i++, 2)); i++;\
            line_8_elements.push_back(this->dec_);\
          }

  SrecDecode::SrecDecode(/* args */)
  {
  }

  std::vector<std::vector<unsigned int>>* SrecDecode::decode_srec(const std::string & content){
    if(content.length()%2){
      return NULL;
    }
    static unsigned int i;
    std::vector<unsigned int> line_8_elements;
    i = 0U;
    for(auto & vec : this->decode_result_){
      vec.clear();
    }
    this->decode_result_.clear();

    this->dec_ = static_cast<unsigned int>(content.substr(i++, 1)[0]);
    line_8_elements.push_back(this->dec_);

    STR_TO_DEC(content.substr(i++, 1));
    line_8_elements.push_back(this->dec_);
    this->type_code_ = this->dec_;

    STR_TO_DEC(content.substr(i++, 2)); ++i;
    line_8_elements.push_back(this->dec_);

    int counter = ((this->type_code_ == 2U) ? 1 : (this->type_code_ == 3U ? 0 : 2));
    for(unsigned int index = 0; index < counter; index++){
      line_8_elements.push_back(0U);
    }

    STR_TO_VECOTR();

    if(((content.length())/2 + 1 + counter + 7) / 8 >= this->decode_result_.size()){
      this->decode_result_.emplace_back(line_8_elements);
    }

    return (&(this->decode_result_));
  }

  SrecDecode::~SrecDecode()
  {
  }

  HexDecode::HexDecode(/* args */):is_extended_addr_(false), extended_addr_(0x0U) {
  }

  std::vector<std::vector<unsigned int>>* HexDecode::decode_hex(const std::string & content){
    if((content.length() - 1)%2){
      return NULL;
    }
    static unsigned int i;
    std::vector<unsigned int> line_8_elements;
    i = 0U;

    for(auto & vec : this->decode_result_){
      vec.clear();
    }
    this->decode_result_.clear();

    this->dec_ = static_cast<unsigned int>(content.substr(i++,1)[0]);
    line_8_elements.push_back(this->dec_);

    STR_TO_DEC(content.substr(i++,2)); i++;
    line_8_elements.push_back(this->dec_);

    line_8_elements.push_back(0U);
    line_8_elements.push_back(0U);

    for(int index = 0; index <= 2; index++){
      STR_TO_DEC(content.substr(i++,2)); i++;
      line_8_elements.push_back(this->dec_);
    }
    this->type_code_ = this->dec_;

    STR_TO_VECOTR();
    // for(; i < content.length();){
    //   if(line_8_elements.size()>7){
    //     this->decode_result_.emplace_back(line_8_elements);
    //     line_8_elements.clear();
    //   }
    //   STR_TO_DEC(content.substr(i++, 2)); i++;
    //   line_8_elements.push_back(this->dec_);
    // }

    if(((content.length() - 1)/2 + 3 + 7) / 8 >= this->decode_result_.size()){
      this->decode_result_.emplace_back(line_8_elements);
    }
    this->process_extended_type();
    this->process_extended_addr();
    return &(this->decode_result_);
  }

  void HexDecode::process_extended_type(){
    if( HEX_EXTENDED_TYPE_CODE == this->type_code_){
      this->extended_addr_ = (this->decode_result_[0][HEX_EXTENDED_INDEX_0] << 8U) +
                            this->decode_result_[1][HEX_EXTENDED_INDEX_1];
      this->extended_addr_ <<= 4;
      this->is_extended_addr_ = true;
    }
  }

  void HexDecode::process_extended_addr(){
    if(this->is_extended_addr_ &&
        this->decode_result_.size() &&
        HEX_EXTENDED_TYPE_CODE != this->type_code_){
      CLEAR_STREAM();
      this->dec_ = (this->decode_result_[0][HEX_CAN_ADDR_2] << 8U)
                        + this->decode_result_[0][HEX_CAN_ADDR_3];
      this->dec_ += this->extended_addr_;
      // std::cout << std::hex <<  this->extended_addr_ << std::endl;
      // printf("x %x\n", this->dec_);
      this->decode_result_[0][HEX_CAN_ADDR_0] = ((this->dec_ & 0xff000000U) >> 24U);
      this->decode_result_[0][HEX_CAN_ADDR_1] = ((this->dec_ & 0xff0000U) >> 16U);
      this->decode_result_[0][HEX_CAN_ADDR_2] = ((this->dec_ & 0xff00U) >> 8U);
      this->decode_result_[0][HEX_CAN_ADDR_3] = ((this->dec_ & 0xffU));
    }
  }

  HexDecode::~HexDecode()
  {
  }
} // namespace ota
