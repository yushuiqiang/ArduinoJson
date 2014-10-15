#pragma once

#include "JsonArray.h"
#include "JsonObject.h"

class JsonParser;

class JsonBuffer
{
    friend class JsonContainer;
    friend class JsonNode;
    friend class JsonParser;

public:
    virtual ~JsonBuffer() {};

    JsonArray createArray()
    {
        return JsonArray(createArrayNode());
    }

    JsonObject createObject()
    {
        return JsonObject(createObjectNode());
    }

    JsonValue createValue();

    JsonArray parseArray(char* string);

protected:
    virtual void* allocateNode() = 0;

private:
    JsonNode* createNode();

    JsonNode* createArrayNode();
    JsonNode* createBoolNode(bool value);
    JsonNode* createDoubleNode(double value, int decimals);
    JsonNode* createLongNode(long value);
    JsonNode* createObjectNode();
    JsonNode* createStringNode(const char* value);
};

