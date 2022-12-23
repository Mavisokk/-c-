#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct information  //产品信息结构体
{
	char ID[30];        //手机编号
	char brand[30];     //品牌
	char model[30];     //型号
	int inprice;        //进价
	int num;           //数量
};
struct sell//产品销售结构体
{
	char ID[30];
	char brand[30];
	char model[30];
	int sellnum;           //销售数量
	int outprice;       //售价
	int sumprice;      //总售价
	struct date
{
	int year;
    int month;
	int day;
}date1;
};
int n,s,i,cn=0,sn=0;
struct information infor[1000];//基本信息数组
struct sell sel[1000];//销售信息数组

void inputOnephone(void);//(1)创建手机基本信息
void add(); //（2）增加手机基本信息
void del();//(3)删除手机基本信息
void modify();//（4）修改手机基本信息
void manage();//（5）手机销售管理
void search();//（6）按不同条件进行查询
void sort(float c[100]);//选择排序
void Top10(int n);//打印前十榜单
void Sumbrand(int n);//按品牌统计
void Sumdate(int n);//按日期统计
void  SUMprice(int n);//按进价统计
void sell();//（7）按不同条件进行统计工作
int loadphone();//从文件中读取手机基本信息
int loadSell();//从文件中读取手机销售信息


void inputOnephone(void)                               //（1）创建手机基本信息文件
{
	FILE *fp;//文件指针
	n=0;
    i=0;
			printf("产品编号:\n");
			scanf("%s",infor[i].ID);
		while(strcmp(infor[i].ID,"*")!=0)//若输入*则退出输入
		{		
		printf("品牌:");
		scanf("%s",infor[i].brand);//品牌
		printf("产品型号:");
		scanf("%s",infor[i].model);//型号
		printf("进价:");
		scanf("%d",&infor[i].inprice);//进价
		printf("库存数量:");
		scanf("%d",&infor[i].num);//库存
		printf("\n");
		n++;i++;//循环该环节
		printf("产品编号:");
		scanf("%s",infor[i].ID);
		}
if((fp=fopen("infor.txt","wb"))==NULL)//创建文件

    {
	printf("can not open the file!");
    exit(-1);
    }
for(i=0;i<n;i++)
    fwrite(&infor[i],sizeof(struct information),1,fp);//将手机信息写入文件
    fclose(fp);
}
void add()                                                //（2）增加手机信息
{   FILE *fp;
if((fp=fopen("infor.txt","ab+"))==NULL)
    {printf("can not open the file!");
    exit(-1);
    }
    printf("\n请输入产品编号\n");
    scanf("%s",infor[i].ID);
    printf("\n请输入品牌\n");
    scanf("%s",infor[i].brand);
    printf("\n请输入产品型号\n");
    scanf("%s",infor[i].model);
    printf("\n请输入进价\n");
    scanf("%d",&infor[i].inprice);
    printf("\n请输入库存量\n");
	scanf("%d",&infor[i].num);
    fwrite(&infor[i],sizeof(struct information),1,fp);    
fclose(fp);
printf("添加完成，继续选择\n\n");
}
void del()                                             //（3）删除手机信息
{	FILE *fp;
	int x=1,j;
	char ID[15],model[15];
	while(x)
	{
    if((fp=fopen("infor.txt","rb+"))==NULL)
    {
	printf("can not open the file!");
    exit(0);
    }
    for(i=0;i<n;i++)
    {
    fread(&infor[i],sizeof(struct information),1,fp);//读取手机信息
    }
    printf("请输入要删除的产品编号");
    scanf("%s",ID);
    printf("请输入要删除的产品型号");
    scanf("%s",model);
    i=0;
 while(((strcmp(infor[i].ID,ID)!=0)||(strcmp(infor[i].model,model)!=0)))  //找到编号和型号相同的手机
i++;
	printf("显示该手机信息:\n");
	printf("%s %s %s %d",infor[i].ID,infor[i].brand,infor[i].model,infor[i].inprice);
	for(j=i+1;j<n;j++)
		infor[j-1]=infor[j];//删除手机信息  覆盖
			n--;
	if(i>=n)
		printf("无该产品编号");

    rewind(fp);                               
    for(i=0;i<n;i++)
    fwrite(&infor[i],sizeof(struct information),1,fp);
    printf("\n已完成操作\n继续删除请输入1，否则输入0");
    scanf("%d",&x); //通过改变x的值来决定是否继续循环
	}
	fclose(fp);//循环结束后关掉文件
}
struct information chID[1];
void modify()           //（4）修改手机信息
{
	FILE *fp;
    int m=1,i,x=1;
    while(x)
	{
        printf("请输入要修改的产品编号");
        scanf("%s",chID[1].ID);
        printf("请输入要修改的产品型号");
        scanf("%s",chID[1].model);
        if((fp=fopen("infor.txt","rb+"))==NULL)
		{printf("can not open the file!");
        exit(0);
		}
		for(i=0;i<n;i++)
			fread(&infor[i],sizeof(struct information),1,fp);//读取文件信息
		for(i=0;i<n;i++)
		{
            if((strcmp(infor[i].ID,chID[1].ID)==0)&&(strcmp(infor[i].model,chID[1].model)==0))//查找手机
			{
				printf("已找到该产品\n");
				m++;
				while(m!=0)
				{
					printf("\n          修改产品编号请输入1\n");
					printf("\n          修改品牌请输入2\n");
                    printf("\n          修改产品型号请输入3\n");
                    printf("\n          修改进价请输入4\n");
                    printf("\n          修改库存数量请输入5\n");                     
                    printf("\n          修改完成请输入0\n");
                    scanf("%d",&m);
					if(m>=0&&m<=5)
					{
						switch(m)
						{
						case 1:{
						printf("原产品编号为%s\n",infor[i].ID);
						printf("输入新产品编号");
                        scanf("%s",chID[1].ID);
						strcpy(infor[i].ID,chID[1].ID);//将新编号代替原来编号
							}
						break;
						case 2: {
						printf("原品牌为%s\n",infor[i].brand);
						printf("输入新品牌");
                        scanf("%s",chID[1].brand);
						strcpy(infor[i].brand,chID[1].brand);
								}
						break;
						case 3: {printf("原产品型号为%s\n",infor[i].model);
						printf("输入新产品型号");
                        scanf("%s",chID[1].model);
						strcpy(infor[i].model,chID[1].model);
								}
						break;
						case 4: {printf("原进价为%d\n",infor[i].inprice);
						printf("输入新进价");
						scanf("%d",&chID[1].inprice);
						infor[i].inprice=chID[1].inprice;
								}
						break;
						case 5: {
						printf("原库存数量为%d\n",infor[i].num);
						printf("输入新库存数量");
                        scanf("%d",&chID[1].num);
						infor[i].num=chID[1].num;
								}
						break;                                  
					case 0:  return;
						break;	
						}//end switch
						if(m)
							printf("操作完成,请继续选择\n");
					}//end if
					else
					printf("操作错误，再次选择\n");			
				}//end while				
			}//end if
		}//end for		
		if(i>=n)
		printf("未找到该产品\n");
		rewind(fp);
		for(i=0;i<n;i++)
        fwrite(&infor[i],sizeof(struct information),1,fp);			
		printf("继续修改请输入1,否则输入0\n");
				scanf("%d",&x);
	}//end while	
	fclose(fp);
}
void manage()                                             //（5）手机销售管理
{ 
	FILE *fp1,*fp;
	i=0;
	s=0;
	if((fp=fopen("infor.txt","rb+"))==NULL)
    {printf("can not open the file!");
    exit(0);
    }  
    printf("请输入产品编号");
    scanf("%s",sel[i].ID);
		while(strcmp(sel[i].ID,"*")!=0)
		{
			printf("请输入品牌");
            scanf("%s",sel[i].brand);
            printf("请输入产品型号");
            scanf("%s",sel[i].model);
            printf("请输入销售数量");
            scanf("%d",&sel[i].sellnum);
            infor[i].num=infor[i].num-sel[i].sellnum;
            printf("请输入销售价格");
            scanf("%d",&sel[i].outprice);
            printf("请输入销售日期");
            printf("请输入年份");
            scanf("%d",&sel[i].date1.year);
            printf("请输入月份");
            scanf("%d",&sel[i].date1.month);
            printf("请输入日期");
            scanf("%d",&sel[i].date1.day);
			printf("\n");
			i++;
			s++;
			printf("请输入产品编号");
            scanf("%s",sel[i].ID);
		}
		if((fp1=fopen("sell.txt","wb+"))==NULL)
		{printf("can not open the file!");
		exit(0);
		}
		for(i=0;i<s;i++)
			fwrite(&sel[i],sizeof(struct sell),1,fp1); 
		for(i=0;i<n;i++)
			fwrite(&infor[i],sizeof(struct sell),1,fp);

		fclose(fp1);
		fclose(fp);
		printf("添加完成，继续选择\n\n");
}
void search()                                             //（6）按不同条件进行查询
{
	FILE *fp1;
char ID[15],brand[15];
	int m=0;
	i=0;
	int year,month,day;
while(1)
{
	printf("\n          按产品编号查询手机信息请输入1\n"); 
    printf("\n          按产品品牌查询销售信息请输入2\n");
    printf("\n          按日期查询请输入3\n");                     
    printf("\n          查询结束请输入4\n");
    scanf("%d",&m);
	getchar();
		switch(m)
		{
		 case 1:  //按编号在信息记录中查
			{
				printf("请输入要查询的产品编号\n");
				scanf("%s",ID);  

				for(i=0;i<n;i++)
				{
					if(strcmp(infor[i].ID,ID)==0)
					{
					printf("产品编号为%s\n",infor[i].ID);
                    printf("品牌为%s\n",infor[i].brand);
                    printf("产品型号为%s\n",infor[i].model);
                    printf("进价为%d\n",infor[i].inprice);
					break;
					}	  
				}
				if(i>=n)
					printf("不存在该产品编号\n");			  
			}
			break;
		 case 2: //按品牌在销售记录中查
			{
				printf("请输入要查询的产品品牌\n");
				scanf("%s",brand);
				if((fp1=fopen("sell.txt","rb+"))==NULL)
				{printf("can not open the file!");
				exit(0);
				}
				for(i=0;i<s;i++)
				{
					fread(&sel[i],sizeof(struct sell),1,fp1);	  
					if(strcmp(sel[i].brand,brand)==0)
					{
					printf("产品编号为%s\n",sel[i].ID);
                    printf("品牌为%s\n",sel[i].brand);
                    printf("产品型号为%s\n",sel[i].model);
                    printf("售价为%d\n",sel[i].outprice);
                    printf("销售数量为%d\n",sel[i].sellnum);
					sel[i].sumprice=sel[i].outprice*sel[i].sellnum;
                    printf("总金额为%d\n",sel[i].sumprice);
                    printf("年份为%d\n",sel[i].date1.year);
                    printf("月份为为%d\n",sel[i].date1.month);
                    printf("号数为%d\n",sel[i].date1.day);
					break;
					}
				}
					if(i>=n)
					printf("未出售该产品\n");			 				  
			}
			break;
		 case 3:  //按日期查询
			{
				printf("请输入要查询的销售日期\n");
                printf("请输入要查询的年份\n");
                scanf("%d",&year);
                printf("请输入要查询的月份\n");
                scanf("%d",&month);
                printf("请输入要查询的号数\n");
                scanf("%d",&day);
				if((fp1=fopen("sell.txt","rb+"))==NULL)
				{printf("can not open the file!");
				exit(0);
				}				 
				for(i=0;i<s;i++)
				{
					fread(&sel[i],sizeof(struct sell),1,fp1);
					
					if((sel[i].date1.day==day)&&(sel[i].date1.month==month)&&(sel[i].date1.year==year))
					{
						printf("产品编号为%s\n",sel[i].ID);
                        printf("品牌为%s\n",sel[i].brand);
                        printf("产品型号为%s\n",sel[i].model);
                        printf("售价为%d\n",sel[i].outprice);
                        printf("销售数量为%d\n",sel[i].sellnum);
						sel[i].sumprice=sel[i].outprice*sel[i].sellnum;
                        printf("总金额为%d\n",sel[i].sumprice);
                        printf("年份为%d\n",sel[i].date1.year);
                        printf("月份为为%d\n",sel[i].date1.month);
                        printf("号数为%d\n",sel[i].date1.day);
						break;
					}
				}
					if(i>=n)
					printf("此日期无销售产品!");	  
			}
			break;
		
		case 4:printf("查询完成，继续选择\n");return; 
		default:printf("按键错误，请重新选择");
        }//end switch


}//end while
}
//=============================================================

void sort(float c[100])//选择排序
{   
	int j,k;
    float t;
	for(j=0;j<99;j++)
	for(k=0;k<99-j;k++)
	if(c[k]<c[k+1])
	{
			t=c[k];
			c[k]=c[k+1];
			c[k+1]=t;
		}
}
void Top10(int n)//打印前十榜单
{
	int i,j;
	float s1=0,c[100];//s1
	for(i=0;i<=n;i++)
	for(j=0;j<=n;j++)
	{
		if(strcmp(infor[i].model,sel[j].model)==0)
		s1=s1+(sel[j].sellnum)*(sel[j].outprice);
		c[i]=s1;
	}
    sort(c);
    for(i=0;i<10;i++)
        printf("第%d名 %s %.2f",i+1,infor[i].model,c[i]);
}
void Sumbrand(int n)              //按品牌统计
{   char str[20];                 
    int s1=0,i;
	float s2=0;
	printf("请输入手机品牌名称\n");
	scanf("%s",str);
	for(i=0;i<n;i++)
	if(strcmp(str,sel[i].brand)==0)
	{
	s1=s1+sel[i].sellnum;
	s2=s2+(sel[i].outprice)*(sel[i].sellnum);
	}
	printf("总销售量%4d,总销售金额%5f",s1,s2);
} 

void Sumdate(int n)                //按日期统计
{   
	int s1=0,a,b,i;
    float s2=0;
	printf("请输入日期(year.month)");
	scanf("%d.%d",&a,&b);
	for(i=0;i<n;i++)
	if(a==sel[i].date1.year&&b==sel[i].date1.month)
	{
		s1=s1+sel[i].sellnum;
		s2=s2+(sel[i].outprice)*(sel[i].sellnum);
	}
	printf("总销售量%d总销售金额%.2f\n",s1,s2);
	Top10(n);
	}

void  SUMprice(int n)             //按进价统计
{
	int   j,k,a[200],t,i;
	for(i=0;i<n;i++)
	a[i]=infor[i].inprice;
	for(j=0;j<n-1;j++)
	for(k=0;k<n-j-1;k++)
		if(a[k]>a[k+1])
		{
			t=a[k];
			a[k]=a[k+1];
			a[k+1]=t;
		}
		for(i=0,j=1;i<n;i++)
    {
		printf("第%d\n",j++);
        printf("%d\n",infor[i].num);
        printf("%s\n",infor[i].model);
		printf("%s\n",infor[i].brand);
		printf("%d\n",infor[i].inprice); 
		printf("%d\n",infor[i].num);
    }
}	

void sell()                                        //（7）按不同条件进行统计工作
{
	int m=0;
	i=0;
	while(m!=5)
	{
		printf("***输入品牌，在销售记录文件中统计其不同型号的销量及销售金额，并输出总销售量和总销售金额请按1\n");
		printf("\n");
		printf("***输入一个日期（年.月），在销售记录文件中统计该月中各个品牌的手机的总销售量，制作排行榜,请按2\n");
		printf("\n");
		printf("***根据进价，从小到大排序，输出信息，请按3\n");
		printf("\n");
		printf("***输入结束，请按4\n");
		printf("\n");
		scanf("%d",&m);
		if(m>=1&&m<=4)
		{
			switch(m)
			{			
			case 1:	Sumbrand(n);
				break;
			case 2: Sumdate(i);
				break;
			case 3: SUMprice(n);
				break;
			case 4: 	return;
				break;
			}//end switch
		}//end if
	}//end while

}
//============================================================================================================//
int loadphone()//从文件中读取手机信息
{
	FILE *fp;
	int cn=0;
	fp=fopen("infor.txt","ab+");
	if(!fp)
	{printf("file can't open\n");exit(0);}
	while(!feof(fp))
	{
		fread(&infor[cn++],sizeof(struct information),1,fp);
	}
	fclose (fp);
	return cn;
}
//==============================================================================================================
int loadSell()//从文件中读取手机销售信息。
{	FILE *fp1;
	int sn=0;
	fp1=fopen("sell.txt","ab+");
	if(!fp1)
		{printf("file can't open\n");exit(0);}
	while(!feof(fp1))
	{
		fread(&sel[sn++],sizeof(struct information),1,fp1);
	}
	fclose (fp1);
	return sn;
}
//===============================================================================================================
int main()                                                        //主函数
{
int m=1;
n=loadphone();
s=loadSell();
system("color 0A");
if(n==0) 
printf("手机信息为空，请先创建！\n");
while(1)
{
		printf("\n");
		printf("\t----------------------------------\n");
		printf("\t*                                *\n");
		printf("\t*      手机销售管理系统          *\n");
		printf("\t*                                *\n");
		printf("\t*     1. 创建手机产品信息        *\n");
		printf("\t*     2. 增加手机信息        *\n");
		printf("\t*     3. 删除手机电脑信息        *\n");
		printf("\t*     4. 修改手机电脑信息        *\n");
		printf("\t*     5. 手机销售管理            *\n");
		printf("\t*     6. 手机销售查询            *\n");
		printf("\t*     7. 手机统计工作            *\n");
		printf("\t*     0. 退出系统                *\n");
		printf("\t*     请选择操作（0-7）:         *\n");
		printf("\t----------------------------------\n");
		scanf("%d",&m);
		getchar();

	switch(m)
	{
			case 1:inputOnephone();//调用创建函数
			break;
            case 2: add();//调用添加函数
			break;
            case 3: del();//调用删除函数
            break;
            case 4: modify();//调用修改函数
            break;
            case 5: manage();//调用创建手机销售函数
            break;
            case 6: search();//调用查找函数
            break;
            case 7: sell();//调用统计函数
            break;
			case 0: exit(0);break;
			default:printf("按键错误，请重新选择！\n");
	}//end switch
}//end while

}

