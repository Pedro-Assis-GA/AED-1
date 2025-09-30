#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1005

typedef struct{
    int data[MAX_SIZE];
    int size;
} DataStr;

void remove_element(DataStr *ds, int index){
    if(index < 0 || index >=ds->size){
        return;
    }
    memmove(ds->data + index, ds->data + index + 1, (ds->size - index - 1) * sizeof(int));
    ds->size--;
}

void solve(){
    int n, cmd, x;

    while(scanf("%d", &n) == 1){

        DataStr s, q, pq;
        s.size = 0;
        q.size = 0;
        pq.size = 0;

        int is_stack = 1;
        int is_queue = 1;
        int is_pq = 1;

        for(int i = 0; i < n; i++){
            if(scanf("%d %d", &cmd, &x) != 2){
                break;
            }

            if(cmd == 1){

                if(s.size < MAX_SIZE) s.data[s.size++] = x;
                if(q.size < MAX_SIZE) q.data[q.size++] = x;
                if(pq.size < MAX_SIZE) pq.data[pq.size++] = x;
                
            }else if(cmd == 2){

                if(s.size == 0){
                    is_stack = is_queue = is_pq = 0;
                    continue;
                }

                if(is_stack){
                    if(s.data[s.size - 1] != x){
                        is_stack = 0;
                    }
                    s.size--;
                }

                if(is_queue){
                    if(q.data[0] != x){
                        is_queue = 0;
                    }
                    remove_element(&q, 0);
                }

                if(is_pq){
                    int max_val = -1;
                    int max_idx = -1;

                    for(int k = 0; k < pq.size; k++){
                        if(pq.data[k] > max_val){
                            max_val = pq.data[k];
                            max_idx = k;
                        }
                    }

                    if(max_val != x){
                        is_pq = 0;
                    }

                    remove_element(&pq, max_idx);
                }
            }
        }
        int count = is_stack + is_queue + is_pq;

        if(count == 0){
            printf("impossible\n");
        } else if(count == 1){
            if (is_stack){
                printf("stack\n");
            } else if(is_queue){
                printf("queue\n");
            } else{
                printf("priority queue\n");
            }
        } else{
            printf("not sure\n");
        }
    }
}

int main(){
    solve();
    return 0;
}
