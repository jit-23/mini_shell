
#include "../minishell.h"




int main()
{
	t_history *cmd_hist;
	char *a;
	int i;

	i  = 0;
	a = NULL;
	while(i++ < 4)
	{
		printf("/$> ");
		scanf("%s", &a);
		//tgetstr(a, );
		printf("\n");
		printf("a - %s", a);
		shell_history(cmd_hist, a); // continue set history, define every histroy line every loop
	}
	
	while(cmd_hist)
	{
		printf("%s\n", cmd_hist->cmd_str);
		cmd_hist = cmd_hist->next;
	}
	return 0;
}
