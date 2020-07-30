
typedef struct ndoe{
    int row;
    int col;
    int val;
    struct node * next;
}nodet;

nodet* newnode(int row,int col,int key){
    nodet* n;
    n = (nodet*)malloc(sizeof(nodet));
    n->row=row;
    n->col=col;
    n->val=key;
    n->next=NULL;
    return n;
}

void enqueue()

int numIslands(char** grid, int gridSize, int* gridColSize){
    int** visited;
    int i,j,r,c;
    nodet *qhead,*q,*tmp;
    
    visited = (int**)malloc(gridSize*sizeof(int*));
    for(i=0;i<gridSize;i++){
        visited[i]=(int*)malloc(gridColSize*sizeof(int));
        for(j=0;j<gridColSize;j++){
            visited[i][j]=0;
        }
    }
    
    //Begin Node in the queue
    r=0;
    c=0;
    qhead = newnode(r,c,grid[r][c]);
    
    //Start to do BFS
    
    while(qhead!=NULL){
        
        q = newnode(r,c,grid[r][c],qhead);
        for(tmp=qhead;tmp->next!=NULL;tmp=tmp->next);
        tmp->next=q;
        
    }
}
