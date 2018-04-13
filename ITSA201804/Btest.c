#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxLine 200

int main()
{
		int n=0,i=0;
		int j=0;
		char line[12][MaxLine];
		char ans[12][50];
		int left=0;
		int right=0;


		scanf("%d\n",&n);

		for(i=0;i<n;i++)
		{


				fgets(line[i],MaxLine,stdin);

		}


		for(i=0;i<n;i++)
		{
            left=0;
            right=0;

			for(j=0;line[i][j]!='\n';j++)
			{
					if(line[i][j]=='(')left++;
					if(line[i][j]==')')right++;
					if(left<right)
					{
							strcpy(ans[i],"No\n");
							break;
					}
			}

            if(left==right)
			{
					strcpy(ans[i],"Yes\n");
			}
			if(left>right)
			{
					strcpy(ans[i],"No\n");
			}



		}


		for(i=0;i<n;i++)
		{
				printf("%s",ans[i]);
		}


		return 0;
}
