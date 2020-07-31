
typedef struct node{
    int row;
    int col;
    char val;
    struct node* next;
}nodet;

nodet* newnode(int row,int col,char key){
    nodet* n;
    n = (nodet*)malloc(sizeof(nodet));
    n->row=row;
    n->col=col;
    n->val=key;
    n->next=NULL;
    return n;
}

int numIslands(char** grid, int gridSize, int *gridColSize){
    int** visited;
    int i,j,k,r,c;
    int n,landnum,listnum,num;
    int rmove[4]={-1,1,0,0};
    int cmove[4]={0,0,-1,1};// up down left right
    nodet *qhead,*q,*tmp;
    
    visited = (int**)malloc(gridSize*sizeof(int*));
    for(i=0;i<gridSize;i++){
        visited[i]=(int*)malloc((*gridColSize)*sizeof(int));
        for(j=0;j<gridColSize;j++){
            visited[i][j]=0;
        }
    }
    
    //Begin Node in the queue WRONG WRONG WRONG
    // r=0;
    // c=0;
    // num=1;
    // qhead = newnode(r,c,grid[r][c]);
    // visited[r][c]=1;
    //Start to do BFS
    
    landnum=0;
    listnum=0;
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize;j++){
            
            if(visited[i][j]==1 || grid[i][j]=='0')
                continue;
            
            //Otherwise grid[i][j]=1 and not visited yet -> put into the queue as the head of the list
            qhead=newnode(i,j,grid[i][j]);
            visited[i][j]=1;
            landnum+=1;
            listnum+=1;
            //Start to BFS
            while(qhead!=NULL){
                
                // num is this time spanning nodes for each level -> current level list length is listnum
                for(num=0;listnum!=0;listnum--){
                    
                    //Take the first one out of the queue
                    q=qhead;
                    r=q->row;
                    c=q->col;
                    qhead=qhead->next;
                    free(q);
                    
                    for(k=0;k<4;k++){
                        // check four directional adjacent nodes of (r,c)                                                 // if( grid[i+rmove[k]][j+cmove[k]] == '1' ){ WRONG
                            if( grid[r+rmove[k]][c+cmove[k]] == '1' && visited[r+rmove[k]][c+cmove[k]]==0 ){ // if it's land '1' add it to the queue
                                
                                q=newnode(r+rmove[k],c+cmove[k],'1'); //create the new node to insert to the end of the list
                                num+=1; // total number of the adjacent nodes of this current set of nodes
                                for(tmp=qhead;tmp!=NULL && tmp->next!=NULL;tmp=tmp->next);                       // length of the list
                                if(tmp==NULL)
                                    qhead=q;
                                else
                                    tmp->next=q;
                                
                                visited[r+rmove[k]][c+cmove[k]]=1; // After insertion the node is treated as visited
                            }
                    }//inner for -> to all adjacent nodes
                    
                }//outer for -> to all nodes in the current level -> take all nodes from the current level -> listnum-- until it's 0 then loop finishes
                
                listnum = num; //update the current list length in the last for loop
            }//while
            
           // All the adjacent(connected nodes are counted as in the same land)
        }
    }
    return landnum;
}
