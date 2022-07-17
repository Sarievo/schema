a := File standardInput readLine asNumber
prev := 1;
curr := 1;
for(i,0,a-2,
    tmp := curr;
    curr := curr+prev;
    prev := tmp;
);
curr println;