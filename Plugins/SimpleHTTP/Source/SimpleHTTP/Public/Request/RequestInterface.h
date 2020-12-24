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
#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"


namespace SimpleHTTP
{
	namespace HTTP
	{
		struct IHTTPClientRequest
		{
			friend struct FHTTPClient;

			IHTTPClientRequest();

			IHTTPClientRequest &operator<<(const FHttpRequestCompleteDelegate& SimpleDelegateInstance)
			{
				HttpReuest->OnProcessRequestComplete() = SimpleDelegateInstance;
				return *this;
			}

			IHTTPClientRequest &operator<<(const FHttpRequestProgressDelegate& SimpleDelegateInstance)
			{			
				HttpReuest->OnRequestProgress() = SimpleDelegateInstance;
				return *this;
			}

			IHTTPClientRequest &operator<<(const FHttpRequestHeaderReceivedDelegate& SimpleDelegateInstance)
			{
				HttpReuest->OnHeaderReceived() = SimpleDelegateInstance;
				return *this;
			}

		protected:
			bool ProcessRequest();
			void CancelRequest();

		protected:
			TSharedPtr<class IHttpRequest> HttpReuest;
		};
	}
}