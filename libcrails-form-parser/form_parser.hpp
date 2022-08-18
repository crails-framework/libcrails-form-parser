#ifndef  CRAILS_FORM_PARSER_HPP
# define CRAILS_FORM_PARSER_HPP

# include <crails/request_parser.hpp>

namespace Crails
{
  class RequestFormParser : public BodyParser
  {
  public:
    void operator()(Context&, std::function<void(RequestParser::Status)>) const override;
  private:
    void body_received(Context&, const std::string& body) const override;
  };
}

#endif
