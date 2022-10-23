#ifndef LH_API_SERVICE_H
#define LH_API_SERVICE_H

#include <functional>
#include <string>

namespace litehtml
{
	class document;

	/// <summary>
	/// XMLHttpRequest
	/// </summary>
	class XMLHttpRequest
	{
	public:
		/// <summary>
		/// Creates a new XMLHttpRequest object
		/// </summary>
		XMLHttpRequest();

		/// <summary>
		/// Cancels the current request
		/// </summary>
		void abort();

		/// <summary>
		/// Returns header information
		/// </summary>
		void getAllResponseHeaders();

		/// <summary>
		/// Returns specific header information
		/// </summary>
		void getResponseHeader();

		/// <summary>
		/// Defines a function to be called when the readyState property changes
		/// </summary>
		std::function<void(XMLHttpRequest*)> onreadystatechange;

		/// <summary>
		/// Specifies the request
		/// </summary>
		/// <param name="method">the request type GET or POST</param>
		/// <param name="url">the file location</param>
		/// <param name="async">true (asynchronous) or false (synchronous)</param>
		/// <param name="user">optional user name</param>
		/// <param name="psw">optional password</param>
		void open(string method, string url, bool async = true, string user = _tdefault, string psw = _tdefault);

		/// <summary>
		/// Holds the status of the XMLHttpRequest.
		/// 0: request not initialized
		/// 1: server connection established
		/// 2: request received
		/// 3: processing request
		/// 4: request finished and response is ready
		/// </summary>
		int readyState();

		/// <summary>
		/// Returns the response data as a string
		/// </summary>
		string responseText();

		/// <summary>
		/// Returns the response data as XML data
		/// </summary>
		document* responseXML();

		/// <summary>
		/// Sends the request to the server
		/// </summary>
		void send(string body = _tdefault);

		/// <summary>
		/// Adds a label/value pair to the header to be sent
		/// </summary>
		void setRequestHeader();

		/// <summary>
		/// Returns the status-number of a request
		/// </summary>
		int status();

		/// <summary>
		/// Returns the status-text
		/// </summary>
		string statusText();
	};
}

#endif  // LH_API_SERVICE_H
