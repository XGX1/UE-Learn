// Copyright (C) RenZhai.2020.All Rights Reserved.
/*
�������ַ���������ʹ�ñ��ײ��
 DocURL��			https://zhuanlan.zhihu.com/p/82195344

 �������ַ������ο�����ǰ�Ĳ��
 MarketplaceURL :   https://www.aboutcg.org/courseDetails/682/introduce

 ������˽�������UE4�̳���ο���
 URL :				https://zhuanlan.zhihu.com/p/60117613

 �����ϵͳ�˽���լϵ�н̳��Լ���ز���������� ���Թ�ע�ҵĲ���
 URL :				http://renzhai.net/

 ������˽�������һ�ڵĿγ̰��ſ��� ������΢�Ź��ں����� ��լ ��ע���� ���ǻ����ͺܶ฻�м���������

 ���˲���            https://weibo.com/BZRZ/profile?s=6cm7D0  //������ʹ�16�굽���� ��������û��ô�ù� �Ժ�˵���������������� �ȷ�������
 */
/*
 SimpleHTTPѧϰ�ĵ�
 UE4������� SimpleHTTP
�汾 1.1
Ŀ¼
ǰ�ù���
�ϴ���Դ
������Դ
ɾ����Դ
SimpleHTTPԴ��ӿ�
��ප�Һã��ҽ���լ����ڿ�����������һ��SimpleHTTPʹ�ü��ɣ�

�ò��Ŀǰ�ṩ�˶�web�����������ϴ����غ�ɾ���ĺ����ӿڣ��ֱ��ǣ�

	   bool GetObject(const FString &URL, const FString &SavePaths);
   bool PutObject(const FString &URL, TArray<uint8> &Data);
   bool PutObject(const FString &URL, const FString &LocalPaths);
   bool PutObject(const FString &URL, TSharedRef<FArchive, ESPMode::ThreadSafe> Stream);
   bool DeleteObject(const FString &URL);
�ò��ʹ����Ҳ�Ƿǳ����㣬���跱�ӵ�ע�ỷ�ڣ�����ʹ�ã�



1.ǰ�ù���
��ʹ�øò����Ҫ����ͷ�ļ�

#include "SimpleHttpManage.h"
������Ҫ������ģ��.Build.cs

SimpleHTTP
һ��׼������ �Ϳ��Դ󵨵�ʹ�ñ�����ˣ�

2.�ϴ���Դ
�����ð�����OSS�����������

	   //���� wersdfd.oss-cn-beijing.aliyuncs.com
   //��ʽ https://<����>/<������>/<������>/...
   //https://wersdfd.oss-cn-beijing.aliyuncs.com/Hello.zip
   FString URL = "https://wersdfd.oss-cn-beijing.aliyuncs.com/Hello.zip";
   FString LocalPaths = "F:/PJ/TestOSS/SimpleHTTP.zip";
   if (!FSimpleHttpManage::Get()->PutObject(URL, LocalPaths))
   {
	   check(0);
   }
3.������Դ
   FString URL = "https://wersdfd.oss-cn-beijing.aliyuncs.com/Hello.zip";
   FString LocalPaths = "F:/PJ/TestOSS/WWWEEEERRR.zip";
   if (!FSimpleHttpManage::Get()->GetObject(URL, LocalPaths))
   {
	   check(0);
   }
4.ɾ����Դ
	   FString URL = "https://wersdfd.oss-cn-beijing.aliyuncs.com/Hello.zip";

	   if (!FSimpleHttpManage::Get()->DeleteObject(URL))
   {
	   check(0);
   }
5.SimpleHTTPԴ��ӿ�
#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

class SIMPLEHTTP_API FSimpleHttpManage
{
public:
   FSimpleHttpManage();
   ~FSimpleHttpManage();

   static FSimpleHttpManage *Get();
   static void Destroy();

   bool GetObject(const FString &URL, const FString &SavePaths);
   bool PutObject(const FString &URL, TArray<uint8> &Data);
   bool PutObject(const FString &URL, const FString &LocalPaths);
   bool PutObject(const FString &URL, TSharedRef<FArchive, ESPMode::ThreadSafe> Stream);
private:

   void HttpRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);
   void HttpRequestProgress(FHttpRequestPtr Request, int32 BytesSent, int32 BytesReceived);
   void HttpRequestHeaderReceived(FHttpRequestPtr Request, const FString& HeaderName, const FString& NewHeaderValue);

   void Print(const FString &Msg,float Time = 10.f,FColor Color = FColor::Red);
private:
   static FSimpleHttpManage	*SimpleHttp;
   FCriticalSection			Mutex;
   FString						TmpSavePaths;
};


���Կ��ó��ǳ��򵥣����������֣��ã��Ǳ��εķ����˽�����лл��

 */

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "SimpleHTTPType.h"
/**
 * 
 */
struct SIMPLEHTTP_API FSimpleHttpActionRequest :public TSharedFromThis<FSimpleHttpActionRequest>
{
public:
	//BP
	FSimpleHttpSingleRequestCompleteDelegate			SimpleHttpRequestCompleteDelegate;
	FSimpleHttpSingleRequestProgressDelegate			SimpleHttpRequestProgressDelegate;
	FSimpleHttpSingleRequestHeaderReceivedDelegate		SimpleHttpRequestHeaderReceivedDelegate;
	FAllRequestCompleteDelegate							AllRequestCompleteDelegate;

	//C++
	FSimpleSingleCompleteDelegate						SimpleCompleteDelegate;
	FSimpleSingleRequestProgressDelegate				SimpleSingleRequestProgressDelegate;
	FSimpleSingleRequestHeaderReceivedDelegate			SimpleSingleRequestHeaderReceivedDelegate;
	FSimpleDelegate										AllTasksCompletedDelegate;

public:
	FSimpleHttpActionRequest();
	virtual ~FSimpleHttpActionRequest();

	//������ͼ
	virtual void GetObjects(const TArray<FString> &URL, const FString &SavePaths);
	virtual void GetObjects(const TArray<FString> &URL);
	virtual void DeleteObjects(const TArray<FString> &URL);

	virtual bool GetObject(const FString &URL);
	virtual bool GetObject(const FString &URL, const FString &SavePaths);
	virtual bool PutObject(const FString &URL, const TArray<uint8> &Data);
	virtual bool PutObject(const FString &URL, const FString &LocalPaths);
	virtual bool PutObject(const FString &URL, TSharedRef<FArchive, ESPMode::ThreadSafe> Stream);
	virtual bool DeleteObject(const FString &URL);
	virtual bool PostObject(const FString &URL);

	FORCEINLINE FString GetPaths() { return TmpSavePaths; }
	FORCEINLINE void SetPaths(const FString &NewPaths) { TmpSavePaths = NewPaths; }
	FORCEINLINE bool IsRequestComplete() { return bRequestComplete; }

protected:
	virtual void HttpRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);
	virtual void HttpRequestProgress(FHttpRequestPtr Request, int32 BytesSent, int32 BytesReceived);
	virtual void HttpRequestHeaderReceived(FHttpRequestPtr Request, const FString& HeaderName, const FString& NewHeaderValue);

	void Print(const FString &Msg, float Time = 10.f, FColor Color = FColor::Red);
protected:
	FString						TmpSavePaths;
	bool						bRequestComplete;
	bool						bSaveDisk;
};
