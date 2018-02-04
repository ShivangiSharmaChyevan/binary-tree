#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class node
{
        int data;
        node *left,*right;
        
        public:
        
        node()
        {
                data=0;
                left=right=NULL;
        }
        
        friend class tree;
};

class tree
{
		public:
        node *root;
        int n;
        
        
        tree()
        {
                root=NULL;
                n=0;
        }
        
        void createit();
        void prerec(node *);
        void postrec(node *);
        void inrec(node *);
        node *returnroot()
        {
        return root;
        }
        void levelorder();
        void particularlevel(int);
        void levelutil(node*,int);
        void initer();
        void preiter();
        void post2iter();
        int height(node*);
        void revlevel();
        void revtree();
        void postwithprein(int in[],int pre[],int n);
        int search(int a[],int n,int x);
        void seperatelevel();
        void diagonal();
        void diagonal1(node*,int,map<int ,vector<int> >&);
        void deletpost(node*);
        int similar(node *,node *);
        int size(node *);
        int sumcompute(node*,int);
        int minheight(node*);
        int maxheight(node*);
        int balance();
        int getleafcount(node*);
        void printpath(int[],int);
        void path(node*,int[],int);
        int subtree(node*,node*);
        int issumtree(node*);
        int sum(node*);
        bool ancestor(node*,int);
        int findlev(node*,int,int);
        void distancek(node*,int);
        void fold(node*);
        bool foldable(node* r1,node* r2);
        void width();
        int findwidth(node*,int);
        void doubletree(node*);
        void complete(node*);
        int levnodecount(node*,int);
};
void tree::complete(node *root)
{
	int ht=maxheight(root);
	
	for(int i=1;i<ht;i++)
	{
		int k=levnodecount(root,i);
		if(k!=pow(2,i-1))
		{
			cout<<"\n Not a complete tree";
			return;
			
		}
		
	}
	cout<<"\n YAyy!A complete tree";
}
int tree::levnodecount(node* root,int i)
{
	
	
	if(root==NULL)
	return 0;
	
	if(i==1)
	return 1;
	else if(i>1)
	{
	
	return levnodecount(root->left,i-1)+levnodecount(root->right,i-1);
	
	}
}
void tree::doubletree(node* root)
{
	if(root==NULL)
	return;
	
	
	doubletree(root->left);
	doubletree(root->right);
	
	
	node *temp=root->left;
	node *k=new node();
	k->data=root->data;

	root->left=k;
	k->left=temp;

	

}
int tree::findwidth(node *root,int k)
{
	if(root==NULL)
	return 0;
	
	 if(k==1)
	return 1;
	
	else if(k>1)
	{
		return findwidth(root->left,k-1)+findwidth(root->right,k-1);
	}
		

	
}
void tree::width()
{
	int ht=maxheight(root);
	int mx=-1,k;
	for(int i=1;i<=ht;i++)
	{
		k=findwidth(root,i);
		if(k>mx)
		mx=k;
	}
	
	cout<<" \n Max width is "<<mx;
	
	
}

void tree::fold(node * r)
{
	if(r==NULL)
	return;
	
	bool p=foldable(r->left,r->right);
	
	if(p)
	cout<<"Yes,TREE is folable"<<"\n";
	else
	cout<<"NO,Tree is not foldable"<<"\n";
	
}
bool tree::foldable(node* r1,node* r2)
{
	if(r1==NULL&&r2==NULL)
		return true;
	if(r1==NULL||r2==NULL)
		return false;
	return foldable(r1->left,r2->right)&&foldable(r1->right,r2->left);
}
void tree::distancek(node* root,int k)
{
	if(root==NULL)
	return ;
	if(k==0)
	{
		cout<<root->data<<" ";
		return ;
	}
	else
	{
	
	distancek(root->left,k-1);
	distancek(root->right,k-1);
	}
	
}
int tree::findlev(node* root,int lev,int t)
{
	if(root==NULL)
	return 0;
	
	if(root->data==t)
	return lev;
	
	int k=findlev(root->left,lev+1,t);
	if(k!=0)
	return k;
	
	k=findlev(root->right,lev+1,t);
	
	return k;
	
	
}
bool tree::ancestor(node *root,int t)
{
	if(root==NULL)
	return false;
	
	if(root->data==t)
	return true;
	
	if(ancestor(root->left,t)||ancestor(root->right,t))
	{
		cout<<root->data<<" ";
		return true;
	}
}
int tree::sum(node * t)
{
	if(t==NULL)
	return 0;
	
	return sum(t->left)+t->data+sum(t->right);
}
int tree::issumtree(node * root)
{
	if(root==NULL||(root->left==NULL&&root->right==NULL))
		return 1;
		
		int ls=sum(root->left);
		int rs=sum(root->right);
		
		return root->data==(ls+rs) && issumtree(root->left)&&issumtree(root->right);
	
}
int tree::subtree(node* t,node* s)
{
	if(s==NULL)
	return 1;
	if(t==NULL)
	return 0;
	
	if (similar(t,s))
	return 1;
	
	return subtree(t->left,s)||subtree(t->right,s);	
}
void tree::path(node *root,int path1[],int len)
{
	if(root==NULL)
	{
		return;
	}
	path1[len++]=root->data;
	if(root->left==NULL&&root->right==NULL)
	{
		
		printpath(path1,len);
		cout<<"\n";
		
	}
	else
	{
		path(root->left,path1,len);
		path(root->right,path1,len);
	}
}
void tree::printpath(int path1[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<path1[i]<<" ";
	}
}
int tree::getleafcount(node* root)
{
	if(root==NULL)
	return 0;
	if(root->left==NULL&&root->right==NULL)
	return 1;
	else
	{
		return getleafcount(root->left)+getleafcount(root->right);
	}
}
int tree::minheight(node* root)
{
	if(root==NULL)
	return 0;
	
	return 1+min(minheight(root->left),minheight(root->right));
}
int tree::maxheight(node* root)
{
	if(root==NULL)
	return 0;
	
	return 1+max(maxheight(root->left),maxheight(root->right));
}
int tree::balance()
{
	return (maxheight(root)-minheight(root)<=1);
}
int tree::sumcompute(node* a,int sum)
{
	if(a==NULL&&sum==0)
	{
		return 1;
	}
	else
	{
		int t=0;
		
		int sum1=sum-a->data;
		
		if(sum1==0&&a->left==NULL&&a->right==NULL)
			return 1;
		
		if(a->left)
		t=t||sumcompute(a->left,sum1);
		if(a->right)
		t=t||sumcompute(a->right,sum1);
		
		return t;
	}
	
	
}
int tree::size(node * a)
{
	if(a==NULL)
	return 0;
	else
	return (size(a->left)+1+size(a->right));
}
int tree::similar(node* a,node* b)
{
	if(a==NULL&&b==NULL)
	{
		return 1;
	}
	if(a!=NULL && b!=NULL)
	{
		return
		(a->data==b->data&&similar(a->left,b->left)&&similar(a->right,b->right));
	}
	
	return 0;
}

void tree::deletpost(node *root)
{
	if(root==NULL)
	return ;
		
	deletpost(root->left);
	deletpost(root->right);
	delete(root);
	
	
}
void tree::diagonal1(node * root,int d,map<int,vector<int> >&m)
{
	if(!root)
	return;
	
	m[d].push_back(root->data);
	
	
		diagonal1(root->left,d+1,m);
	
		diagonal1(root->right,d,m);
}
void tree::diagonal()
{
		map<int ,vector<int> > m;
		
		diagonal1(root,0,m);
		
		map<int ,vector<int> >::iterator i;
		vector<int>::iterator it;
		for( i=m.begin();i!=m.end();i++)
		{
			for( it=i->second.begin();it!=i->second.end();++it)
			cout<<*it<<"  ";
			
			cout<<"\n";
		}
		
}
void tree::seperatelevel()
{
	queue<node*>q1;
	queue<node*>q2;
	
	node*temp=root;
	
	if(root==NULL)
	return;
	q1.push(root);
	while(!q1.empty()||!q2.empty())
	{
	
		while(!q1.empty())
		{
			temp=q1.front();
			q1.pop();
			cout<<temp->data<<"  ";
			if(temp->left)
			q2.push(temp->left);
			if(temp->right)
			q2.push(temp->right);
		}
		
		cout<<"\n";
		
		while(!q2.empty())
		{
				temp=q2.front();
				q2.pop();
			cout<<temp->data<<"  ";
			if(temp->left)
			q1.push(temp->left);
			if(temp->right)
			q1.push(temp->right);
		}
		
		cout<<"\n";
		
		
	}
}
int tree::search(int a[],int x,int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==x)
		return i;
	}
	return -1;
}
void tree::postwithprein(int in[],int pre[],int n)
{
	int root=search(in,pre[0],n);
	
		if(root!=0)
		postwithprein(in,pre+1,root);
		
		if(root!=n-1)
		postwithprein(in+root+1,pre+root+1,n-root-1);
			
		cout<<pre[0]<<" ";
	
}
void tree::revtree()
{
	int h=height(root);
	
	for(int i=h;i>=1;i--)
	{
		particularlevel(i);
	}
}
void tree::revlevel()
{
	node *temp=root;
	queue<node*>q;
	stack<node *>s;
	q.push(root);
	
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		s.push(temp);
		if(temp->right)
		q.push(temp->right);
		if(temp->left)
		q.push(temp->left);
	}
	
	while(!s.empty())
	{
		temp=s.top();
		s.pop();
		cout<<temp->data<<" ";
	}
}
int tree::height(node * root)
{
	if(root==NULL)
	return 0;
	else
	{
		int l=height(root->left);
		int r=height(root->right);
		
		if(l>r)
		return (l+1);
		else 
		return (r+1);
	}
}
void tree::post2iter()
{
	if(root==NULL)
	return;
	stack<node*>s1;
	stack<node*>s2;
	s1.push(root);
	while(!s1.empty())
	{
		node *temp=s1.top();
		s1.pop();
		s2.push(temp);
		if(temp->left)
		s1.push(temp->left);
		if(temp->right)
		s1.push(temp->right);
	}
	
	while(!s2.empty())
	{
		node *d=s2.top();
		s2.pop();
		cout<<d->data<<" ";
		
	}
}

void tree::particularlevel(int lev)
{
	levelutil(root,lev);
}

void tree::levelutil(node*root,int lev)
{
	if(root==NULL)
		return;
	
	if(lev==1)
	cout<<root->data<<" ";
	else if(lev>1)
	{
	
	levelutil(root->left,lev-1);
	levelutil(root->right,lev-1);
	}
}
void tree::createit()
{
        cout<<"\n Enter the number of nodes ";
        cin>>n;
        
       char ch;
        
        for(int i=0;i<n;++i)
        {
                node *p=new node();
                
                cout<<"\n Enter data";
                cin>>p->data;
                
                if(i==0)
                {
                root=p;
                }
                
                else
                {
                        node *r=root;
                        
                        while(1)
                        {
                                cout<<"\n Enter to left(l)/right(r) of "<<r->data<<" ?";
                                cin>>ch;
                                if(ch=='l')
                                {
                                        
                                        if(r->left==NULL)
                                        {
                                        r->left=p;
                                        break;
                                        }
                                        else
                                        r=r->left;
                                        
                                }
                                  if(ch=='r')
                                {
                                        
                                        if(r->right==NULL)
                                        {
                                        r->right=p;
                                        break;
                                        }
                                        else
                                        r=r->right;
                                        
                                }
                        }
                }
        }
}
void tree::inrec(node *root)
{
       if(root==NULL)
       {
	
        return;
    	}
        inrec(root->left);
        cout<<root->data<<" ";
        inrec(root->right);
        
        
        
}
void tree::postrec(node * root)
{
        if(root==NULL)
        return;
        postrec(root->left);
        postrec(root->right);
        
        cout<<root->data<<" ";
}

void tree::prerec(node *root)
{
        if(root==NULL)
        return;
        cout<<root->data<<" ";
        prerec(root->left);
        prerec(root->right);
}

void tree::levelorder()
{
	if(root==NULL)
	return ;
	queue<node*>q;
	
	q.push(root);
	
	while(!q.empty())
	{
		node *temp=q.front();
		
		cout<<temp->data<<" ";
		
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
			
		q.pop();
	}
	
	
	
}
void tree::initer()
{
	stack<node*>s;
	node*temp=root;

	while(temp!=NULL||!s.empty())
	{
		while(temp!=NULL)
		{
		s.push(temp);
		temp=temp->left;
		
		}
		
		temp=s.top();
		s.pop();
		
		cout<<temp->data<<" ";
		
		temp=temp->right;
		
	}
	
}
void tree::preiter()
{
	stack<node*>s;
	node*temp=root;

	while(temp!=NULL||!s.empty())
	{
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
		s.push(temp);
		temp=temp->left;
		
		}
		
		temp=s.top();
		s.pop();
		
		
		
		temp=temp->right;
		
	}
	
}


int main()
{
    tree t;
    
    t.createit();
    int ch1;
    int lev;
    int ht;
    int in[10],pre[10];
	int n1;    
	node *temp;
	 tree t1,t2;
	
    while(1)
    {
    	int ch;
    	cout<<"\nPress 1 for inorder ";
    	cout<<"\nPress 2 for preorder ";
    	cout<<"\nPress 3 for postorder";
    	cout<<"\nPress 4 for LevelOrder";
    	cout<<"\nPress 5 for prining any particular level";
    	cout<<"\nPress 6 for printing in reverse order";
    	cout<<"\nPress 7 for finding height of tree";
    	cout<<"\nPress 8 for making postorder using inorder and preorder ";
    	cout<<"\nPress 9 for Level Order traversal ,each level sepearately ";
    	cout<<"\nPress 10 for diagonal wise printing";
    	cout<<"\nPress 11 for deleting  tree";
    	cout<<"\nPress 12 for comparing two tree for similarity ";
    	cout<<"\nPress 13 for calculating size ";
   		cout<<"\nPress 14 for root to leaf sum ";
   		cout<<"\nPress 15 for findning if tree is balanced";
   		cout<<"\nPress 16 for counting leafnodes in th tree";
   		cout<<"\nPress 17 for entering new tree";
   		cout<<"\nPress 18 for printing all paths to leaf";
   		cout<<"\nPress 19 for finding if the given tree is subset of another tree";
   		cout<<"\nPress 20 for finding whether given is sum tree or not";
   		cout<<"\nPress 21 for printing ancestors of a given node ";
   		cout<<"\nPress 22 for finding level of tree";
   		cout<<"\nPress 23 for finding nodes at distance k";
   		cout<<"\nPress 24 for finding if the tree is foldable";
   		cout<<"\nPress 25 for finding the max width of tree";
   		cout<<"\nPress 26 for making double of the tree";
   		cout<<"\nPress 27 for exit ";
    	cout<<"\nEnter the choice :";
    	cin>>ch;
    	
		switch(ch)
		{
			case 1:	if(t.returnroot()==NULL)
					{
						cout<<"\n Empty tree ";
						break;
					}
			
					cout<<"\n INORDER (rec): ";
  					t.inrec(t.returnroot());
  					cout<<"\n INORDER ITERATIVE WITH STACK: ";
  					t.initer();
					 break;
			case 2:	cout<<"\n PREORDER (rec):";
  					t.prerec(t.returnroot());
  					cout<<"\n PREORDER ITERATIVE WITH STACK: ";
  					t.preiter();
					 break;
			case 3:cout<<"\n POSTORDER (rec): ";
					t.postrec(t.returnroot());
					cout<<"\n POSTORDER ITERATIVE WITH 2 STACK: ";
  					t.post2iter();
					break;
			case 4:cout<<"\n LEVELORDER(Using Queue) : ";
					t.levelorder();
					break;
			case 5:cout<<"\n Enter Level";
					cin>>lev;
					t.particularlevel(lev);
					break;
			case 6: cout<<"\n Reverse level order traversal (with stack and queue)";
					t.revlevel();
					cout<<"\n Reverse order (without stack)";
					t.revtree();
					
					break;
			case 7:cout<<"\n Height of the tree is : ";
				   ht=t.height(t.returnroot());
				   cout<<ht<<"\n";
				   break;
			case 8:cout<<"\n enter size";
				   cin>>n1;
				   cout<<"\n Enter inorder : ";
				   for(int i=0;i<n1;i++)
				   {
				   	cin>>in[i];
				   }
				   cout<<"\nEnter preorder : ";
				   for(int i=0;i<n1;i++)
				   {
				   	cin>>pre[i];
				   }
				   cout<<"\n Postorder : ";
				   t.postwithprein(in,pre,n1);
				   break;
			case 9:t.seperatelevel();
					break;
			case 10:t.diagonal();
					break;
			case 11:t.deletpost(t.returnroot());
					t.root=NULL;
					break;
			case 12: t1.createit();
					t2.createit();
					n1=t.similar(t1.root,t2.root);
					if(n1==1)
					{
						cout<<"Yayy!! They are identical ";
					}
					else
					{
						
						cout<<"No ,they are not identical ";
					}
					break;
			case 13: n1=t.size(t.returnroot());
						cout<<"\n size is : "<<n1;
						break;
			case 14: cout<<"Enter the sum value : ";
					 cin>>n1;
					 lev=t.sumcompute(t.root,n1);
					 if(lev==1)
					 {
					 		cout<<"\nYayy!! Sum found ";
					 }
					 else
					 {
					 	cout<<"\n Not Found";
					 }
					 break;
			case 15:lev=t.balance();
					if(lev==0)
					{
						cout<<"\nSorry! Not balanced";
					}
					else
					{
						cout<<"\nYAYY! Balanced it is";
					}
					break;
			case 16:lev=t.getleafcount(t.root);
					cout<<"\n NO. of leaf nodes "<<lev<<"\n";
					break;
			case 17:t.createit();
					break;
			case 18:t.path(t.root,in,0);
					break;
			case 19:
					cout<<"\n ENter tree";
					t1.createit();
					cout<<"\n Enter subtree to find ";
					t2.createit();
					lev=t.subtree(t1.root,t2.root);
					if(lev==1)
					{
						cout<<"\n Yes , it is a subtree";
					}
					else
					cout<<"n Not a subtree";
					break;
			case 20:lev=t.issumtree(t.root);
					if(lev==0)
					{ 
						cout<<"\n NOT a sum tree ";
						
					}
					else
					cout<<"\n Yayy! A sum tree";
					break;
			case 21:
					cout<<"\n Enter the target ";
					cin>>lev;
					t.ancestor(t.root,lev);
					break;
		    case 22:
		    		cout<<"\n Enter the target ";
		    		cin>>lev;
		    		lev=t.findlev(t.root,1,lev);
		    		cout<<" level is : "<<lev;
		    		break;
		    case 23:
		    		cout<<"\n Enter the value of k";
		    		cin>>lev;
		    		t.distancek(t.root,lev);
		    		break;
		    case 24:
					t.fold(t.root);
					break;	
			case 25:t.width();
					break;
			case 26:t.doubletree(t.root);
						break;	
					
			case 27:return 0;		
					
				
		}	
    
    
  	}
}
