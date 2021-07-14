#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tree_node* treeptr;
typedef struct tree_node{
	char id;
	char name[10];
	treeptr lchild;
	treeptr rsibling;
}treenode;

treeptr root, current_node;



char insertLCRS(char *nodename, char a)
{
    treenode* newnode = (treeptr)malloc(sizeof(treenode));
    newnode ->lchild = NULL;
    newnode ->rsibling = NULL;
    newnode -> id = a;
    strcpy(newnode->name, nodename);
    if(current_node -> lchild == NULL)
        current_node -> lchild = newnode;
    else
    {
        treenode* tempnode = root -> lchild;
        while(tempnode ->rsibling != NULL)
            tempnode = tempnode -> rsibling;
    }
}
void preorderprint()
{
   if (root != NULL)
   {
      printf("%s ",root -> name);
      preorderprint(root->lchild);
      preorderprint(root->rsibling);
   }
}
void change_folder(treeptr root,char* nodename)
{
    if(root!= NULL)
    {
        if(strcmp(root -> name, nodename) == 0)
            current_node = root;
        else
        {
            if(root->id =='d')
                change_folder(root->lchild, nodename);
            else
                change_folder(root->rsibling, nodename);
        }
    }
}

void delete_file(char *nodename)
{
    free(nodename);

}
void delete_directory(treeptr root, char* nodename)
{
    if(strcmp(root -> name, nodename) == 0)
    {
        root -> lchild = NULL;
        root -> rsibling = NULL;
        free(root);
    }
    else
    {
        delete_directory(root->lchild, nodename);
        delete_directory(root->rsibling, nodename);
    }
}
int main()
{
	root = (treeptr)malloc (sizeof (treenode));
	root->id = 'd';
	strcpy(root->name, "root");
	root->lchild = root->rsibling = NULL;
	current_node = root;
	insertLCRS("bskim", 'd');
	preorderprint();
	change_folder(root ,"bskim");
	insertLCRS("homework1", 'f');
	preorderprint();
    insertLCRS("homework2", 'f');
	preorderprint();
	insertLCRS("project", 'd');
	preorderprint();
	change_folder(root,"project");
	insertLCRS("program1", 'f');
	preorderprint();
	change_folder(root,"root");
	insertLCRS("yslee", 'd');
	preorderprint();
	change_folder(root,"yslee");
	insertLCRS("mylab", 'f');
	preorderprint();
	change_folder(root,"yskim");
	change_folder(root,"bskim");
    delete_file("homework2");
    preorderprint();
    change_folder(root,"bskim");
    delete_directory(root, "project");
    preorderprint();
    return 0;
}
