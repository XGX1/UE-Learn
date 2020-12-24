#include "Client/HTTPClient.h"

FHTTPClient::FHTTPClient()
{

}

auto FHTTPClient::GetObject(FGetObjectRequest& Request) -> bool
{
	return Request.ProcessRequest();
}

bool FHTTPClient::DeleteObject(FDeleteObjectsRequest &Request)
{
	return Request.ProcessRequest();
}

bool FHTTPClient::PutObject(FPutObjectRequest &Request)
{
	return Request.ProcessRequest();
}

void FHTTPClient::AbortRequest(IHTTPClientRequest &Request)
{
	Request.CancelRequest();
}

bool SimpleHTTP::HTTP::FHTTPClient::PostObject(FPostObjectsRequest &Request)
{
	return Request.ProcessRequest();
}