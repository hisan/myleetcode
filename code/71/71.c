给定一个文档 (Unix-style) 的完全路径，请进行路径简化。
例如，
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
边界情况:
你是否考虑了 路径 = "/../" 的情况？
在这种情况下，你需返回 "/" 。
此外，路径中也可能包含多个斜杠 '/' ，如 "/home//foo/" 。
在这种情况下，你可忽略多余的斜杠，返回 "/home/foo" 。

//2018-12-27
//2018-12-28   "/EQnvK///U/./../LQnJc/./rI/Ckzz/lmO/./"
//2018-12-29   "/...",    "/.",   "/.."
char* simplifyPath(char* path) {
    typedef struct stack
    {
        char character[1000];
        int top;
    }stack;
    char *newpath;
    int i = 0;
    int dotcount = 0;
    stack *s1 = (stack *)malloc(sizeof(stack));
    memset(s1,0,sizeof(stack));
    if(path[0]=='\0')
    {
        return NULL;
    }
    while(path[i]!='\0')
    {
        switch(path[i])
        {
            case '/':
                if(dotcount==1&&s1->character[s1->top-1]=='.')
               {
                   dotcount = 0;
                   s1->top-=1;
                   if(s1->character[s1->top-1]!='/')
                   {
                       s1->character[s1->top]=path[i];
                       s1->top++;
                       i++;
                       break;
                   }
                   else
                   {
                       i++;
                       break;
                   }
               }
               else if(dotcount==2&&s1->character[s1->top-1]=='.')
               {    
                  
                    dotcount = 0;
                    s1->top-=2;
                   
                    
                    if(s1->top==1&&s1->character[s1->top-1]=='/')
                    {
                       i++;
                       break;
                    }
                    s1->top-=1;
                    while(s1->top>0&&s1->character[s1->top-1]!='/')
                    {
                        s1->top--;
                    }
                    if(s1->character[s1->top-1]!='/')
                    {
                       s1->character[s1->top]=path[i];
                       s1->top++;
                       i++;
                       break;
                    }
                    else
                    {
                       i++;
                       break;
                    }
               }
               else
               {
                   if(s1->top>0)
                   {
                        if(s1->character[s1->top-1]=='/')
                        {
                            i++;
                            break;
                        }
                   }
                    s1->character[s1->top]=path[i];
                    s1->top++;
                    i++;
                    break;
               }
            case '.':
                dotcount++;
                //i++;顺序错误
                s1->character[s1->top]=path[i];
                i++;
                s1->top++;
                break;
            default:
                dotcount=0;
                s1->character[s1->top]=path[i];
                s1->top++;
                i++;
                break;
        }
    }
    
    if(s1->top>1)
    {
        if(dotcount==2&&s1->character[s1->top-1]=='.')
        {
            dotcount=0;
            s1->top-=2;
            if(s1->top>1&&s1->character[s1->top-1]=='/')
            {   
                s1->top-=1;
                while(s1->top>0&&s1->character[s1->top-1]!='/')
                {
                    s1->top--;
                }
            }
        }
        if(dotcount==1&&s1->character[s1->top-1]=='.')
        {    
            dotcount=0;
             s1->top-=1;
        }
        if(s1->top>1&&s1->character[s1->top-1]=='/')
        {
            s1->top--;
        }
        
        
    }
    newpath = (char *)malloc(sizeof(char)*(s1->top+20));//多分配字节留给结束符
    strncpy(newpath,s1->character,s1->top);//拷贝不带结束符的字符串
    newpath[s1->top]='\0';//手动添加结束符
    return newpath;
}

int main()
{
    //char *p ="/";典型错误，指针存地址不存常量//"/EQnvK///U/./../LQnJc/./rI/Ckzz/lmO/./";
    char p[]="/EQnvK///U/./../LQnJc/./rI/Ckzz/lmO/./";//"/";
    char *path = simplifyPath(p);
    printf("%sthe length is %d\n",path,strlen(path));
    system("pause");
    return 0;
}







