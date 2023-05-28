#include "html.h"

/// <summary>
/// XMLHttpRequest
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Creates a new XMLHttpRequest object
	/// </summary>
	XMLHttpRequest::XMLHttpRequest() { }

	/// <summary>
	/// Cancels the current request
	/// </summary>
	void XMLHttpRequest::abort() { }

	/// <summary>
	/// Returns header information
	/// </summary>
	void XMLHttpRequest::getAllResponseHeaders() { }

	/// <summary>
	/// Returns specific header information
	/// </summary>
	void XMLHttpRequest::getResponseHeader() { }

	/// <summary>
	/// Defines a function to be called when the readyState property changes
	/// </summary>
	//void XMLHttpRequest::onreadystatechange() { }

	/// <summary>
	/// Specifies the request
	/// </summary>
	/// <param name="method">the request type GET or POST</param>
	/// <param name="url">the file location</param>
	/// <param name="async">true (asynchronous) or false (synchronous)</param>
	/// <param name="user">optional user name</param>
	/// <param name="psw">optional password</param>
	void XMLHttpRequest::open(string method, string url, bool async /*= true*/, string user /*= _tdefault*/, string psw /*= _tdefault*/) { }

	/// <summary>
	/// Holds the status of the XMLHttpRequest.
	/// 0: request not initialized
	/// 1: server connection established
	/// 2: request received
	/// 3: processing request
	/// 4: request finished and response is ready
	/// </summary>
	int XMLHttpRequest::readyState() { return 0; }

	/// <summary>
	/// Returns the response data as a string
	/// </summary>
	string XMLHttpRequest::responseText() { return ""; }

	/// <summary>
	/// Returns the response data as XML data
	/// </summary>
	document::ptr XMLHttpRequest::responseXML() { return nullptr; }

	/// <summary>
	/// Sends the request to the server
	/// </summary>
	void XMLHttpRequest::send(string body /*= _tdefault*/) { }

	/// <summary>
	/// Adds a label/value pair to the header to be sent
	/// </summary>
	void XMLHttpRequest::setRequestHeader() { }

	/// <summary>
	/// Returns the status-number of a request
	/// </summary>
	int XMLHttpRequest::status() { return 0; }

	/// <summary>
	/// Returns the status-text
	/// </summary>
	string XMLHttpRequest::statusText() { return ""; }
}
