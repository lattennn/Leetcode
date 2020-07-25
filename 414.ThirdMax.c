
//Given a non-empty array of integers, return the third maximum number in this array. 
//If it does not exist, return the maximum number. The time complexity must be in O(n).

#include<stdlib.h>
#include<stdio.h>

int thirdMax(int* nums, int numsSize){
    int count[3]={-10000,-10000,-10000};
    int i,flag=0;
    printf("Hey %d %d %d!\n",count[0],count[1],count[2]);
    for(i=0;i<numsSize;i++){
        count[0]=(nums[i]>count[0])?nums[i]:count[0];
        //count[1]=(nums[i]<count[0]&&nums[i]>count[1])?nums[i]:count[1]; WRONG
        //count[2]=(nums[i]<count[0]&&nums[i]<count[1]&&nums[i]>count[2])?nums[i]:count[2]; WRONG
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]<count[0]&&nums[i]>count[1])
            count[1]=nums[i];
    }

    for(i=0;i<numsSize;i++){
        if(nums[i]<count[1]&&nums[i]>=count[2]){
            flag=1;
            count[2]=nums[i];
        }
    }
    
    if(flag==0)
        printf("%d",count[0]);
    else
        printf("%d",count[2]);
    return 0;
}

int main(){
    int* array;
    int n,i;
    scanf("%d",&n);
    array=(int*)malloc(n*sizeof(int));
    printf("Insert %d numbers!\n",n);

    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    thirdMax(array,n);

}
