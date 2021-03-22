#include <cstdio>
#include <cstring>

class CMyString
{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str);
    void Print();
	
private:
    char* m_pData;
};

CMystring::CMystring(char *pData)
{
	if (pData == NULL)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else 
	{
		int len = strlen(pData);
		m_pData = new char[len+1];
		strcpy(m_pData,pData);
	}
}

CMyString::CMyString(const CMyString &str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
    delete[] m_pData;
}

CMystring& CMystring::operator =(const CMystring &str)
{
	if (this == &str)
		return *this;
	
	{
		CMystring strTemp(str);
		char *pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	
	return *this;
}
// ====================测试代码====================
void CMyString::Print()
{
    printf("%s", m_pData);
}

void Test1()
{
    printf("Test1 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

// 赋值给自己
void Test2()
{
    printf("Test2 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.Print();
    printf(".\n");
}

// 连续赋值
void Test3()
{
    printf("Test3 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

int main()
{
	return 0;
}


#if 0   //使用g++的编译错误，why?????????
root@ubuntu:/home/zyb/CODE/LEETCODE/myleetcode/JZ_OFFER/2_chapter# g++ -o test operator_reload.cpp -Wall
operator_reload.cpp:18:1: error: ‘CMystring’ does not name a type
 CMystring::CMystring(char *pData)
 ^
operator_reload.cpp:45:1: error: ‘CMystring’ does not name a type
 CMystring& CMystring::operator =(const CMystring &str)
 ^
operator_reload.cpp: In function ‘void Test1()’:
operator_reload.cpp:69:18: warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
     char* text = "Hello world";
                  ^
operator_reload.cpp: In function ‘void Test2()’:
operator_reload.cpp:87:18: warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
     char* text = "Hello world";
                  ^
operator_reload.cpp: In function ‘void Test3()’:
operator_reload.cpp:104:18: warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
     char* text = "Hello world";
                  ^
root@ubuntu:/home/zyb/CODE/LEETCODE/myleetcode/JZ_OFFER/2_chapter#


#endif

