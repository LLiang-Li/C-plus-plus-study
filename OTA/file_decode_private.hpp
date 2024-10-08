#ifndef _DECODE_HPP_
#define _DECODE_HPP_

#include <sstream>
#include <vector>
#include <string>

namespace ota
{

  class OtaToCan;

  class HexDecode
  {
    friend class OtaToCan;
  private:
    /* data */
    std::stringstream str_to_dec_;
    std::string string_;
    unsigned int dec_;
    bool is_extended_addr_;
    unsigned int extended_addr_;
    unsigned int type_code_;
    std::vector<std::vector<unsigned int>> decode_result_;
  private:
    HexDecode(/* args */);
    std::vector<std::vector<unsigned int>>* decode_hex(const std::string & content);
    void process_extended_type();
    void process_extended_addr();
    ~HexDecode();
  };

  class SrecDecode
  {
    friend class OtaToCan;
  private:
    /* data */
    std::stringstream str_to_dec_;
    std::string string_;
    unsigned int dec_;
    unsigned int type_code_;
    std::vector<std::vector<unsigned int>> decode_result_;
  private:
    SrecDecode(/* args */);
    std::vector<std::vector<unsigned int>>* decode_srec(const std::string & content);
    ~SrecDecode();
  };
} // namespace ota


#endif