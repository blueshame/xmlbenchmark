/*
 * Copy: Copyright (C),2020-2020, FlyWant Tech. Co., Ltd.
 * Description: main entry.
 * Author: zhouhaifeng
 * Date: 2020-03-07
 */

#include <libxml/parser.h>
#include <iostream>
 #include <unistd.h>

int main()
{
	const char* fileName = "/opt/source/xmlbenchmark/try.xml";
	xmlDocPtr doc = xmlParseFile(fileName);
	xmlNodePtr root = xmlDocGetRootElement(doc);
	std::cout << "root name:" << root->name << std::endl;
	xmlNodePtr templateNodePtr = root->children;
	while (templateNodePtr != nullptr) {
		if (templateNodePtr->type != XML_ELEMENT_NODE) {
			std::cout << "it does not element node <<" << templateNodePtr->type << std::endl;
			templateNodePtr = templateNodePtr->next;
			continue;
		}

		if (xmlStrcmp(templateNodePtr->name, BAD_CAST("template")) != 0) {
			std::cout << "it does not template node <<" << templateNodePtr->name << std::endl;
			templateNodePtr = templateNodePtr->next;
			continue;
		}
		templateNodePtr = templateNodePtr->next;
	}
	
	sleep(60);
	xmlFreeDoc(doc);
    return 0;
}