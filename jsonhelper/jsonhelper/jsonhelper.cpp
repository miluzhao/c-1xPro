// jsonhelper.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;
//1.头文件
#include "jsonhelper.h"

//2.结构体定义

//二级节点信息Ext 增加节点id
struct TSASecNodeItemExt
{
public:
	TSASecNodeItemExt() {}

	string nodeNo;
	string nodeId;
	string nodeName;
	string extInfo;

	const Json::Value ToJsonWithNode()const;
	const std::string ToJson()const;
	bool FromJson(const Json::Value& jsonNode);
	bool FromJson(const std::string& json_string);
};

//一级节点信息Ext 增加节点id
struct TSAFstNodeItemExt
{
public:
	TSAFstNodeItemExt() {}

	string nodeNo;
	string nodeId;
	string nodeName;
	string extInfo;
	std::list<TSASecNodeItemExt> secNodeItems;

	const Json::Value ToJsonWithNode()const;
	const std::string ToJson()const;
	bool FromJson(const Json::Value& jsonNode);
	bool FromJson(const std::string& json_string);
};

//设备信息Ext 增加节点id
struct TSADevInfoExt
{
public:
	TSADevInfoExt() {}

	string devId;
	string extInfo;
	std::list<TSAFstNodeItemExt> fstNodeItems;

	const Json::Value ToJsonWithNode()const;
	const std::string ToJson()const;
	bool FromJson(const Json::Value& jsonNode);
	bool FromJson(const std::string& json_string);
};

//3.结构体实现
const Json::Value TSASecNodeItemExt::ToJsonWithNode()const
{
	Json::Value node;
	JSonHelper::ToJson::AddChildNode(node, "nodeNo", nodeNo);
	JSonHelper::ToJson::AddChildNode(node, "nodeId", nodeId);
	JSonHelper::ToJson::AddChildNode(node, "nodeName", nodeName);
	JSonHelper::ToJson::AddChildNode(node, "extInfo", extInfo);
	return node;
}

const std::string TSASecNodeItemExt::ToJson()const
{
	return ToJsonWithNode().toStyledString();
}

bool TSASecNodeItemExt::FromJson(const Json::Value& jsonNode)
{

	JSonHelper::ToStruct::ParseChildNode(jsonNode, "nodeNo", nodeNo);
	JSonHelper::ToStruct::ParseChildNode(jsonNode, "nodeId", nodeId);
	JSonHelper::ToStruct::ParseChildNode(jsonNode, "nodeName", nodeName);
	JSonHelper::ToStruct::ParseChildNode(jsonNode, "extInfo", extInfo);
	return true;
}

bool TSASecNodeItemExt::FromJson(const std::string& json_string)
{
	Json::Reader reader;
	Json::Value jsonNode;

	if (!reader.parse(json_string, jsonNode))
	{
		return false;
	}

	return FromJson(jsonNode);
}

//////////////////////////////////////////////////////////////
const Json::Value TSAFstNodeItemExt::ToJsonWithNode()const
{
	Json::Value node;
	JSonHelper::ToJson::AddChildNode(node, "nodeNo", nodeNo);
	JSonHelper::ToJson::AddChildNode(node, "nodeId", nodeId);
	JSonHelper::ToJson::AddChildNode(node, "nodeName", nodeName);
	JSonHelper::ToJson::AddChildNode(node, "extInfo", extInfo);
	JSonHelper::ToJson::AddContainer(node, "secNodeItems", secNodeItems);
	return node;
}

const std::string TSAFstNodeItemExt::ToJson()const
{
	return ToJsonWithNode().toStyledString();
}

bool TSAFstNodeItemExt::FromJson(const Json::Value& jsonNode)
{

	JSonHelper::ToStruct::ParseChildNode(jsonNode, "nodeNo", nodeNo);
	JSonHelper::ToStruct::ParseChildNode(jsonNode, "nodeId", nodeId);
	JSonHelper::ToStruct::ParseChildNode(jsonNode, "nodeName", nodeName);
	JSonHelper::ToStruct::ParseChildNode(jsonNode, "extInfo", extInfo);
	JSonHelper::ToStruct::ParseContainer(jsonNode, "secNodeItems", secNodeItems);
	return true;
}

bool TSAFstNodeItemExt::FromJson(const std::string& json_string)
{
	Json::Reader reader;
	Json::Value jsonNode;

	if (!reader.parse(json_string, jsonNode))
	{
		return false;
	}

	return FromJson(jsonNode);
}

const Json::Value TSADevInfoExt::ToJsonWithNode()const
{
	Json::Value node;
	JSonHelper::ToJson::AddChildNode(node, "devId", devId);
	JSonHelper::ToJson::AddChildNode(node, "extInfo", extInfo);
	JSonHelper::ToJson::AddContainer(node, "fstNodeItems", fstNodeItems);
	return node;
}

const std::string TSADevInfoExt::ToJson()const
{
	return ToJsonWithNode().toStyledString();
}

bool TSADevInfoExt::FromJson(const Json::Value& jsonNode)
{

	JSonHelper::ToStruct::ParseChildNode(jsonNode, "devId", devId);
	JSonHelper::ToStruct::ParseChildNode(jsonNode, "extInfo", extInfo);
	JSonHelper::ToStruct::ParseContainer(jsonNode, "fstNodeItems", fstNodeItems);
	return true;
}

bool TSADevInfoExt::FromJson(const std::string& json_string)
{
	Json::Reader reader;
	Json::Value jsonNode;

	if (!reader.parse(json_string, jsonNode))
	{
		return false;
	}

	return FromJson(jsonNode);
}


int main()
{
	string temp = "{\"devId\" : \"174d1ee0e424438e9b2fd42e124738f8\"}";
	TSADevInfoExt tSADevInfoExt;
	tSADevInfoExt.FromJson(temp);

	std::cout << tSADevInfoExt.ToJson().c_str();

    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
