#include <iostream>

#include "ota.hpp"

namespace ota
{
  OtaToCan::OtaToCan(/* args */):
    hex_decode_(new HexDecode), srec_decode_(new SrecDecode){
  }

  OtaToCan* OtaToCan::instance(){
    static OtaToCan ota_can;
    return (&ota_can);
  }

  std::vector<std::vector<unsigned int>>* OtaToCan::start_decode(const std::string& content){
    this->decode_result_ = content[0] == ':' ?
      this->hex_decode_->decode_hex(content):
      (content[0] == 'S' ?
      this->srec_decode_->decode_srec(content):
      NULL);
    return this->decode_result_;
  }

  void OtaToCan::clear_hex_extended_flg(){
    this->hex_decode_->is_extended_addr_ = false;
    this->hex_decode_->extended_addr_ = 0x0U;
  }

  void OtaToCan::clear_srec_extended_flg(){

  }

  std::vector<std::vector<unsigned int>> const* OtaToCan::get_decode_result() const{
    return this->decode_result_;
  }

  std::vector<std::vector<unsigned int>>* OtaToCan::get_decode_result(){
    return this->decode_result_;
  }

  std::vector<std::vector<unsigned int>> const * OtaToCan::get_hex_result() const{
    return &this->hex_decode_->decode_result_;
  }

  std::vector<std::vector<unsigned int>>* OtaToCan::get_hex_result(){
    return &this->hex_decode_->decode_result_;
  }

  std::vector<std::vector<unsigned int>> const * OtaToCan::get_srec_result() const{
    return &(this->srec_decode_->decode_result_);
  }
  std::vector<std::vector<unsigned int>>* OtaToCan::get_srec_result(){
    return &(this->srec_decode_->decode_result_);
  }

  OtaToCan::~OtaToCan(){
    delete this->srec_decode_;
    delete this->hex_decode_;
  }
} // namespace ota
