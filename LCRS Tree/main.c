#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tree_node *treeptr;
typedef struct tree_node {
	char id;
	char name[10];
	treeptr lchild, rsibling;
}tree_node;

treeptr root, current_node;


char a;
char insertLCRS(char *nodename, a)
{
    newnode = (treeptr)malloc(sizeof(tree_node));
    newnode -> id = a;
    strcpy(newnode->name, nodename);
    if(current_node -> lchild == NULL)
        current_node -> lchlid = newnode;
    else
        lastnode -> rsibling = newnode;

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
void change_folder(char* nodename)
{

    if(root->name == nodename)
        current_node -> id = newnode -> id;
    else
    {
        while(1)
        {
            lnode = root -> lchild;
            if(root -> lchild != NULL)
            {
                if(lnode -> name == newnode->name)
                    lnode = newnode;
                else
                    lnode ->
        }
    }
}
    void change_folder(char* given_name)
    {
        if (root != NULL)
        {
            if (strcmp(root->name, given_name) == 0)
                curr_node = root;
            else
            {
                if (root->id == 'd')
                    change_folder(root->child, given_name);
                else
                    change_folder(root->sibling, given_name);
            }
        }
    }
void main()
{
	root = (treeptr)malloc (sizeof (tree_node));
	root->id = 'd';
	strcpy(root->name, "root");
	root->lchild = root->rsibling = NULL;
	current_node = root;
	insertLCRS("bskim", 'd');
	preorderprint();
	change_folder ("bskim");
	insertLCRS("homework1", 'f');
	preorderprint();
    insertLCRS("homework2", 'f');
	preorderprint();
	insertLCRS("project", 'd');
	preorderprint();
	change_folder("project");
	insertLCRS("program1", 'f');
	preorderprint();
	change_folder("root");
	insertLCRS("yslee", 'd');
	preorderprint();
	change_folder("yslee");
	insertLCRS("mylab", 'f');
	preorderprint();
	change_folder("yskim");
    return 0;
}
