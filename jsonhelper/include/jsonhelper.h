/*========================================================================================
模块名    ：jsoncpp
文件名    ：jsonhelper.h
相关文件  ：
实现功能  ：jsoncpp调用的封装
作者      ：zhouhao
版权      ：<Copyright(C) 2003-2017 Suzhou Keda Technology Co., Ltd. All rights reserved.>
-------------------------------------------------------------------------------------------
修改记录：
日期               版本              修改人             走读人              修改记录
2017/11/27         V1.0              zhouhao                                新建文件
=========================================================================================*/
#ifndef _JSON_HELPER_H
#define _JSON_HELPER_H

#include <string>
#include <vector>
#include <list>
#include <set>
#include "json.h"

namespace JSonHelper{
namespace ToJson{
/************************************************************************/
/* 针对结构体的添加                                                     */
/************************************************************************/
template <typename Type>
inline void AddChildNode(Json::Value& theParent,const char* szFieldName,const Type& theValue){
	theParent[szFieldName] = theValue.ToJsonWithNode();	
}

template <>
inline void AddChildNode<unsigned char>(Json::Value& theParent,const char* szFieldName,const unsigned char& theValue){
	theParent[szFieldName] = theValue;
}

template <>
inline void AddChildNode<char>(Json::Value& theParent,const char* szFieldName,const char& theValue){
    theParent[szFieldName] = theValue;
}

template <>
inline void AddChildNode<unsigned short>(Json::Value& theParent,const char* szFieldName,const unsigned short& theValue){
    theParent[szFieldName] = theValue;
}

template <>
inline void AddChildNode<signed short>(Json::Value& theParent,const char* szFieldName,const signed short& theValue){
    theParent[szFieldName] = theValue;
}

template <>
inline void AddChildNode<unsigned int>(Json::Value& theParent,const char* szFieldName,const unsigned int& theValue){
    theParent[szFieldName] = theValue;
}

template <>
inline void AddChildNode<signed int>(Json::Value& theParent,const char* szFieldName,const signed int& theValue){
    theParent[szFieldName] = theValue;
}

template <>
inline void AddChildNode<unsigned long>(Json::Value& theParent,const char* szName,const unsigned long& theValue){
	theParent[szName] = (unsigned int)theValue;
}

template <>
inline void AddChildNode<signed long>(Json::Value& theParent,const char* szFieldName,const signed long& theValue){
    theParent[szFieldName] = (signed int)theValue;
}

template <>
inline void AddChildNode<std::string>(Json::Value& theParent,const char* szFieldName,const std::string& theValue){
    theParent[szFieldName] = theValue;
}

template <>
inline void AddChildNode<bool>(Json::Value& theParent,const char* szFieldName,const bool& theValue){
    theParent[szFieldName] = theValue;
}

/************************************************************************/
/* 浮点型转字符串再进行传递                                             */
/************************************************************************/
template <>
inline void AddChildNode<float>(Json::Value& theParent,const char* szFieldName,const float& theValue){
	theParent[szFieldName] = theValue;
}

template <>
inline void AddChildNode<double>(Json::Value& theParent,const char* szFieldName,const double& theValue){
	theParent[szFieldName] = theValue;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
template <typename Type>
void SetContainerNode(Json::Value& containerNode,const Type& theValue){
    containerNode.append(theValue.ToJsonWithNode());
}

template <>
inline void SetContainerNode<unsigned char>(Json::Value& containerNode,const unsigned char& theValue){
    containerNode.append(theValue);
}

template <>
inline void SetContainerNode<char>(Json::Value& containerNode,const char& theValue){
    containerNode.append(theValue);
}

template <>
inline void SetContainerNode<unsigned short>(Json::Value& containerNode,const unsigned short& theValue){
    containerNode.append(theValue);
}

template <>
inline void SetContainerNode<signed short>(Json::Value& containerNode,const signed short& theValue){
    containerNode.append(theValue);
}

template <>
inline void SetContainerNode<unsigned int>(Json::Value& containerNode,const unsigned int& theValue){
    containerNode.append(theValue);
}

template <>
inline void SetContainerNode<signed int>(Json::Value& containerNode,const signed int& theValue){
    containerNode.append(theValue);
}

/*template <>
inline void SetContainerNode<unsigned long>(Json::Value& containerNode,const unsigned long& theValue){
    containerNode.append(theValue);
}*/

/*template <>
inline void SetContainerNode<signed long>(Json::Value& containerNode,const signed long& theValue){
    containerNode.append((signed int)theValue);
}*/

template <>
inline void SetContainerNode<std::string>(Json::Value& containerNode,const std::string& theValue){
    containerNode.append(theValue);
}

template <>
inline void SetContainerNode<bool>(Json::Value& containerNode,const bool& theValue){
    containerNode.append(theValue);
}

template <>
inline void SetContainerNode<float>(Json::Value& containerNode,const float& theValue){
	containerNode.append(theValue);
}

template <>
inline void SetContainerNode<double>(Json::Value& containerNode,const double& theValue){
	containerNode.append(theValue);
}


////list,vector,map针对套结构体
template <typename ContainerType>
void AddContainer(Json::Value& theParent,const char* szFieldName, const ContainerType& container){
	size_t count = container.size();
	Json::Value containerNode;
	if(count > 0)
	{
		typename ContainerType::const_iterator iter = container.begin();
		typename ContainerType::const_iterator end  = container.end();
		for(size_t index = 0; iter != end; ++iter,++index){
			SetContainerNode(containerNode, *iter);
		}
	}

	theParent[szFieldName] = containerNode;
}

} //end ToJson

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

namespace ToStruct{
// parse child node, node is nonprimitive by default.
template <typename Type>
inline void ParseChildNode(const Json::Value& jsonNode,const char* szFieldName,Type& output){
	if(jsonNode[szFieldName].isNull()){
		return;
	}

	output.FromJson(jsonNode[szFieldName]);
}


template <>
inline void ParseChildNode<unsigned char>(const Json::Value& jsonNode,const char* szFieldName,unsigned char& output){
	if(jsonNode[szFieldName].isNull()){
		return;
	}
    output = (unsigned char)jsonNode[szFieldName].asInt();
}

template <>
inline void ParseChildNode<char>(const Json::Value& jsonNode,const char* szFieldName,char& output){
	if(jsonNode[szFieldName].isNull()){
		return;
	}
	output = (char)jsonNode[szFieldName].asInt();
}

template <>
inline void ParseChildNode<unsigned short>(const Json::Value& jsonNode,const char* szFieldName,unsigned short& output){
    if(jsonNode[szFieldName].isNull()){
		return;
	}

	output = (unsigned short)jsonNode[szFieldName].asInt();
}

template <>
inline void ParseChildNode<signed short>(const Json::Value& jsonNode,const char* szFieldName,signed short& output){
    if(jsonNode[szFieldName].isNull()){
		return;
	}
	
	output = (signed short)jsonNode[szFieldName].asInt();
}

template <>
inline void ParseChildNode<unsigned int>(const Json::Value& jsonNode,const char* szFieldName,unsigned int& output){
    if(jsonNode[szFieldName].isNull()){
		return;
	}
	
	output = jsonNode[szFieldName].asUInt();
}

template <>
inline void ParseChildNode<signed int>(const Json::Value& jsonNode,const char* szFieldName,signed int& output){
    if(jsonNode[szFieldName].isNull()){
		return;
	}
	
	output = jsonNode[szFieldName].asInt();
}

template <>
inline void ParseChildNode<unsigned long>(const Json::Value& jsonNode,const char* szFieldName,unsigned long& output){
    if(jsonNode[szFieldName].isNull()){
		return;
	}
	
	output = jsonNode[szFieldName].asUInt64();
}

template <>
inline void ParseChildNode<signed long>(const Json::Value& jsonNode,const char* szFieldName,signed long& output){
    if(jsonNode[szFieldName].isNull()){
		return;
	}
	
	output = jsonNode[szFieldName].asInt();
}

template <>
inline void ParseChildNode<std::string>(const Json::Value& jsonNode,const char* szFieldName,std::string& output){
    if(jsonNode[szFieldName].isNull()){
		return;
	}
	
	output = jsonNode[szFieldName].asString();
}

template <>
inline void ParseChildNode<bool>(const Json::Value& jsonNode,const char* szFieldName,bool& output){
	if(jsonNode[szFieldName].isNull()){
		return;
	}
	
	output = jsonNode[szFieldName].asBool();
}

template <>
inline void ParseChildNode<float>(const Json::Value& jsonNode,const char* szFieldName,float& output){
	if(jsonNode[szFieldName].isNull()){
		return;
	}
	
	output = jsonNode[szFieldName].asFloat();
}

template <>
inline void ParseChildNode<double>(const Json::Value& jsonNode,const char* szFieldName,double& output){
	if(jsonNode[szFieldName].isNull()){
		return;
	}
	
	output = jsonNode[szFieldName].asDouble();
}

//////////////////////////////////////////////////////////////////////////
//parse current node
template <typename Type>
void ParseCurNode(const Json::Value& jsonNode,Type& output){
	output.FromJson(jsonNode);
}

template <>
inline void ParseCurNode<unsigned char>(const Json::Value& jsonNode,unsigned char& output){
    if(jsonNode.isNull()){
		return;
	}
	output = (unsigned char)jsonNode.asInt();
}

template <>
inline void ParseCurNode<char>(const Json::Value& jsonNode,char& output){
    if(jsonNode.isNull()){
		return;
	}
	
	output = (char)jsonNode.asInt();
}

template <>
inline void ParseCurNode<unsigned short>(const Json::Value& jsonNode,unsigned short& output){
    if(jsonNode.isNull()){
		return;
	}
	
	output = (unsigned short)jsonNode.asInt();
}

template <>
inline void ParseCurNode<signed short>(const Json::Value& jsonNode,signed short& output){
    if(jsonNode.isNull()){
		return;
	}
	
	output = (signed short)jsonNode.asInt();
}


template <>
inline void ParseCurNode<unsigned int>(const Json::Value& jsonNode,unsigned int& output){
    if(jsonNode.isNull()){
		return;
	}
	
	output = jsonNode.asUInt();
}

template <>
inline void ParseCurNode<signed int>(const Json::Value& jsonNode,signed int& output){
    if(jsonNode.isNull()){
		return;
	}
	
	output = jsonNode.asInt();
}

template <>
inline void ParseCurNode<unsigned long>(const Json::Value& jsonNode,unsigned long& output){
    if(jsonNode.isNull()){
		return;
	}
	
	output = jsonNode.asUInt64();
}

template <>
inline void ParseCurNode<signed long>(const Json::Value& jsonNode,signed long& output){
    if(jsonNode.isNull()){
		return;
	}
	
	output = jsonNode.asInt();
}

template <>
inline void ParseCurNode<std::string>(const Json::Value& jsonNode,std::string& output){
    if(jsonNode.isNull()){
		return;
	}
	
	output = jsonNode.asString();
}

template <>
inline void ParseCurNode<bool>(const Json::Value& jsonNode,bool& output){
    if(jsonNode.isNull()){
		return;
	}
	
	output = jsonNode.asBool();
}

template <>
inline void ParseCurNode<float>(const Json::Value& jsonNode,float& output){
	if(jsonNode.isNull()){
		return;
	}
	
	output = jsonNode.asFloat();
}

template <>
inline void ParseCurNode<double>(const Json::Value& jsonNode,double& output){
	if(jsonNode.isNull()){
		return;
	}
	
	output = jsonNode.asDouble();
}

////list,vector,set
template <typename ContainerType>
void ParseContainer(const Json::Value& jsonNode,const char* szFieldName, ContainerType& outContainer){
	if(jsonNode[szFieldName].isNull()){
		return;
	}

	Json::Value arrayObj = jsonNode[szFieldName];
	int count = arrayObj.size();
	if (0 == count){return;}
	
	outContainer.clear();
	for (int i = 0; i < count; ++i)
	{
		typename ContainerType::value_type v;
		ParseCurNode(arrayObj[i],v);
		outContainer.push_back(v);
	}
}

} //end toStruct
	;
} //JSonHelper
#endif