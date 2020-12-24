#pragma once

#define DEFINITION_HTTP_TYPE(VerbString,Content) \
HttpReuest->SetURL(URL);\
HttpReuest->SetVerb(TEXT(##VerbString));\
HttpReuest->SetHeader(TEXT("Content-Type"), TEXT(##Content)); 

#define REQUEST_BIND_FUN(RequestClass) \
Request \
<< FHttpRequestHeaderReceivedDelegate::CreateRaw(this, &RequestClass##::HttpRequestHeaderReceived)\
<< FHttpRequestProgressDelegate::CreateRaw(this, &RequestClass##::HttpRequestProgress)\
<< FHttpRequestCompleteDelegate::CreateRaw(this, &RequestClass##::HttpRequestComplete);

#define SIMPLE_HTTP_REGISTERED_REQUEST_BP(TYPE) \
auto Handle = RegisteredHttpRequest(TYPE, \
	BPResponseDelegate.SimpleHttpRequestCompleteDelegate, \
	BPResponseDelegate.SimpleHttpRequestProgressDelegate, \
	BPResponseDelegate.SimpleHttpRequestHeaderReceivedDelegate, \
	BPResponseDelegate.AllRequestCompleteDelegate)

#define SIMPLE_HTTP_REGISTERED_REQUEST(TYPE) \
auto Handle = RegisteredHttpRequest(TYPE, \
	BPResponseDelegate.SimpleCompleteDelegate, \
	BPResponseDelegate.SimpleSingleRequestProgressDelegate, \
	BPResponseDelegate.SimpleSingleRequestHeaderReceivedDelegate, \
	BPResponseDelegate.AllTasksCompletedDelegate)

inline void RequestPtrToSimpleRequest(FHttpRequestPtr Request, FSimpleHttpRequest &SimpleHttpRequest)
{
	
	if (Request.IsValid())
	{
		SimpleHttpRequest.Verb = Request->GetVerb();
		SimpleHttpRequest.URL = Request->GetURL();
		SimpleHttpRequest.Status = static_cast<FSimpleHttpStarte>(Request->GetStatus());
		SimpleHttpRequest.ElapsedTime = Request->GetElapsedTime();
		SimpleHttpRequest.ContentType = Request->GetContentType();
		SimpleHttpRequest.ContentLength = Request->GetContentLength();
		SimpleHttpRequest.AllHeaders = Request->GetAllHeaders();
	}
}

inline void ResponsePtrToSimpleResponse(FHttpResponsePtr Response, FSimpleHttpResponse &SimpleHttpResponse)
{
	if (Response.IsValid())
	{
		SimpleHttpResponse.ResponseCode = Response->GetResponseCode();
		SimpleHttpResponse.URL = Response->GetURL();
		SimpleHttpResponse.ResponseMessage = Response->GetContentAsString();
		SimpleHttpResponse.ContentType = Response->GetContentType();
		SimpleHttpResponse.ContentLength = Response->GetContentLength();
		SimpleHttpResponse.AllHeaders = Response->GetAllHeaders();
		SimpleHttpResponse.Content->Content = const_cast<TArray<uint8>*>(&Response->GetContent());
	}
}