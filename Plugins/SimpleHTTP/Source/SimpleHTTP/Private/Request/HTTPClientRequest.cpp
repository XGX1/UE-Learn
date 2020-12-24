// Copyright (C) RenZhai.2020.All Rights Reserved.
#include "Request/HTTPClientRequest.h"
#include "Core/SimpleHttpMacro.h"
#include "SimpleHTTPLog.h"

SimpleHTTP::HTTP::FPutObjectRequest::FPutObjectRequest(const FString &URL, const FString& ContentString)
{
	DEFINITION_HTTP_TYPE("PUT","application/x-www-form-urlencoded")
	HttpReuest->SetContentAsString(ContentString);

	UE_LOG(LogSimpleHTTP, Log, TEXT("PUT Action as string"));
}

SimpleHTTP::HTTP::FPutObjectRequest::FPutObjectRequest(const FString &URL, TSharedRef<FArchive, ESPMode::ThreadSafe> Stream)
{
	DEFINITION_HTTP_TYPE("PUT", "application/x-www-form-urlencoded")
	HttpReuest->SetContentFromStream(Stream);

	UE_LOG(LogSimpleHTTP, Log, TEXT("PUT Action by stream."));
}

SimpleHTTP::HTTP::FPutObjectRequest::FPutObjectRequest(const FString &URL,const TArray<uint8>& ContentPayload)
{
	DEFINITION_HTTP_TYPE("PUT", "application/x-www-form-urlencoded")
	HttpReuest->SetContent(ContentPayload);

	UE_LOG(LogSimpleHTTP, Log, TEXT("PUT Action by content."));
}
//GET���ӷ�������ȡ��Դ
//POST���ڷ������½�һ����Դ��
//PUT���ڷ�����������Դ ->�ͻ����ṩ�ı���������Դ
//PATCH:�ڷ�����������Դ ->�ͻ����ṩ�ı������
//DELETE:�ӷ�����ɾ����Դ��
//HEAD����ȡ��Դ��Ԫ���ݡ�
//OPTIONS����ȡ��Ϣ��������Դ����Щ�����ǿͻ��˿��Ըı�ġ�
SimpleHTTP::HTTP::FGetObjectRequest::FGetObjectRequest(const FString &URL)
{
	DEFINITION_HTTP_TYPE("GET", "application/x-www-form-urlencoded")

	UE_LOG(LogSimpleHTTP, Log, TEXT("GET Action."));
}

SimpleHTTP::HTTP::FDeleteObjectsRequest::FDeleteObjectsRequest(const FString &URL)
{
	DEFINITION_HTTP_TYPE("DELETE", "application/x-www-form-urlencoded")

	UE_LOG(LogSimpleHTTP, Log, TEXT("DELETE Action."));
}

FPostObjectsRequest::FPostObjectsRequest(const FString &URL)
{
	DEFINITION_HTTP_TYPE("POST", "application/x-www-form-urlencoded")

	UE_LOG(LogSimpleHTTP, Log, TEXT("POST Action."));
}