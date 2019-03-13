        int a[3] = {0,};
        a[0]=1;
        a[1]=2;
        a[2]=3;
        int curr=a[0], next=0;
        for(int i=0; i<2;i++)
        {
                next=a[i+1];
                a[i+1]=curr;
                curr=next;
        }
        cout<<"Test part"<<endl;
        for(int i=0;i<3;i++)
                cout<<a[i]<<" ";


