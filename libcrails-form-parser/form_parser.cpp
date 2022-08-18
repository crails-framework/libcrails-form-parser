#include "form_parser.hpp"
#include <crails/context.hpp>
#include <crails/url.hpp>

using namespace std;
using namespace Crails;

void RequestFormParser::operator()(Context& context, function<void(RequestParser::Status)> callback) const
{
  static const regex is_form("application/x-www-form-urlencoded", regex_constants::extended);
  const HttpRequest& request = context.connection->get_request();

  if (request.method() != HttpVerb::get && content_type_matches(request, is_form))
  {
    wait_for_body(context, [callback]()
    {
      callback(RequestParser::Stop);
    });
  }
  else
    callback(RequestParser::Continue);
}

void RequestFormParser::body_received(Context& context, const string& body) const
{
  if (body.size() > 0)
    cgi2params(context.params.as_data(), body);
}
