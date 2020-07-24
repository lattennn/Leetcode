#include<stdlib.h>
#include<stdio.h>

int thirdMax(int* nums, int numsSize){
    int count[3]={-10000,-10000,-10000};
    int i;
    printf("Hey %d %d %d!\n",count[0],count[1],count[2]);
    for(i=0;i<numsSize;i++){
        count[0]=(nums[i]>count[0])?nums[i]:count[0];
        //count[1]=(nums[i]<count[0]&&nums[i]>count[1])?nums[i]:count[1];
        //count[2]=(nums[i]<count[0]&&nums[i]<count[1]&&nums[i]>count[2])?nums[i]:count[2];
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]<count[0]&&nums[i]>count[1])
            count[1]=nums[i];
    }

    for(i=0;i<numsSize;i++){
        if(nums[i]<count[1]&&nums[i]>count[2])
            count[2]=nums[i];
    }

    printf("These:%d %d %d \n",count[0],count[1],count[2]);
    if(count[2]<0)
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
