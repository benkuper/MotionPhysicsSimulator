/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== default.mpsLayout ==================
static const unsigned char temp_binary_data_0[] =
"{\r\n"
"  \"mainLayout\": {\r\n"
"    \"type\": 1,\r\n"
"    \"width\": 1041,\r\n"
"    \"height\": 515,\r\n"
"    \"direction\": 2,\r\n"
"    \"shifters\": [\r\n"
"      {\r\n"
"        \"type\": 1,\r\n"
"        \"width\": 1041,\r\n"
"        \"height\": 515,\r\n"
"        \"direction\": 1,\r\n"
"        \"shifters\": [\r\n"
"          {\r\n"
"            \"type\": 0,\r\n"
"            \"width\": 635,\r\n"
"            \"height\": 515,\r\n"
"            \"currentContent\": \"Vizualizer\",\r\n"
"            \"tabs\": [\r\n"
"              {\r\n"
"                \"name\": \"Vizualizer\"\r\n"
"              }\r\n"
"            ]\r\n"
"          },\r\n"
"          {\r\n"
"            \"type\": 1,\r\n"
"            \"width\": 399,\r\n"
"            \"height\": 515,\r\n"
"            \"direction\": 2,\r\n"
"            \"shifters\": [\r\n"
"              {\r\n"
"                \"type\": 0,\r\n"
"                \"width\": 399,\r\n"
"                \"height\": 266,\r\n"
"                \"currentContent\": \"Inspector\",\r\n"
"                \"tabs\": [\r\n"
"                  {\r\n"
"                    \"name\": \"Inspector\"\r\n"
"                  }\r\n"
"                ]\r\n"
"              },\r\n"
"              {\r\n"
"                \"type\": 0,\r\n"
"                \"width\": 399,\r\n"
"                \"height\": 242,\r\n"
"                \"currentContent\": \"Logger\",\r\n"
"                \"tabs\": [\r\n"
"                  {\r\n"
"                    \"name\": \"Logger\"\r\n"
"                  }\r\n"
"                ]\r\n"
"              }\r\n"
"            ]\r\n"
"          }\r\n"
"        ]\r\n"
"      }\r\n"
"    ]\r\n"
"  },\r\n"
"  \"windows\": null\r\n"
"}";

const char* default_mpsLayout = (const char*) temp_binary_data_0;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;
    if (resourceNameUTF8 != 0)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x21661dfc:  numBytes = 1332; return default_mpsLayout;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "default_mpsLayout"
};

const char* originalFilenames[] =
{
    "default.mpsLayout"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
    {
        if (namedResourceList[i] == resourceNameUTF8)
            return originalFilenames[i];
    }

    return nullptr;
}

}
