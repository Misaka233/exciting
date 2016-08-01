
#include <string>
#include <iostream>
#include <malloc.h>
using namespace std;

//���������ʾ������
typedef struct BiNode
{
	char data;//�ڵ�����
	struct BiNode * lchild;//����
    struct BiNode * rchild;//�Һ���
}BiNode, * BiTree;

//��ǰ�����к��������н����������Ĺ���
void CreateBiTree(BiTree & t,string presequence,string insequence)//tΪҪ�����Ķ�����,presequence��insequence�ֱ�Ϊǰ�����������
{
   if(presequence.length()==0)
   {
         t=NULL;
		 return ;
   }
   char rootNode=presequence[0];//��
   int index=insequence.find(rootNode);//�������������е�λ��
   string lchild_insequence=insequence.substr(0,index);//���ӵ���������
   string rchild_insequence=insequence.substr(index+1);//�Һ��ӵ���������
   int lchild_length=lchild_insequence.length();//���ӵĳ���
   int rchild_length=rchild_insequence.length();//�Һ��ӵĳ���
   string lchild_presequence=presequence.substr(1,lchild_length);//���ӵ�ǰ������
   string rchild_presequence=presequence.substr(1+lchild_length);//�Һ��ӵ�ǰ������

   t=(BiTree)malloc(sizeof(BiNode));
   if(t!=NULL)
   {
	   t->data=rootNode;
       CreateBiTree(t->lchild,lchild_presequence,lchild_insequence);//�ݹ鴴������
	   CreateBiTree(t->rchild,rchild_presequence,rchild_insequence);//�ݹ鴴���Һ���
   }
}

//�����Ƿ񴴽��ɹ�
//�ݹ�ǰ�����������
 void PreOrderTraverse(BiTree & t)
 {
	 if(t!=NULL)
	 {
		 cout<<t->data;
         PreOrderTraverse(t->lchild);
         PreOrderTraverse(t->rchild);
	 }
 }

 //�ݹ����������������
void InOrderTraverse(BiTree & t)
 {
	 if(t!=NULL)
	 {

         InOrderTraverse(t->lchild);
		 cout<<t->data;
         InOrderTraverse(t->rchild);
	 }
 }
void hou(BiTree &t)
{
    if(t!=NULL)
    {
        hou(t->lchild);
        hou(t->rchild);
        cout<<t->data;
    }
}
int main()
{
    BiTree t;
	//string presequence="ABCDEFG";
	//string insequence ="CBEDAFG";
	string qian,zhong;
	cin>>qian>>zhong;
	CreateBiTree(t,qian,zhong);

	PreOrderTraverse(t);
	cout<<endl;
	InOrderTraverse(t);
	cout<<endl;
	hou(t);
	system("PAUSE");
	return 0;
}
