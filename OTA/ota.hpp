#ifndef _OTA_HPP_
#define _OTA_HPP_

#include<string>
#include<vector>
#include<sstream>

#include "file_decode_private.hpp"

namespace ota
{
  class OtaToCan
  {
  private:
    /* data */
    SrecDecode* srec_decode_;
    HexDecode* hex_decode_;
    std::vector<std::vector<unsigned int>>* decode_result_;
  private:
    OtaToCan(/* args */);
    ~OtaToCan();
  public:
    static OtaToCan* instance();
    std::vector<std::vector<unsigned int>>* start_decode(const std::string & content);
    void clear_hex_extended_flg();
    void clear_srec_extended_flg();
    std::vector<std::vector<unsigned int>> const * get_decode_result() const;
    std::vector<std::vector<unsigned int>>* get_decode_result();
    std::vector<std::vector<unsigned int>> const * get_hex_result() const;
    std::vector<std::vector<unsigned int>>* get_hex_result();
    std::vector<std::vector<unsigned int>> const * get_srec_result() const;
    std::vector<std::vector<unsigned int>>* get_srec_result();
  };

} // namespace ota
#endif