#include "../../include/minishell.h"

static int ft_process_heredoc_redir(t_redir *redir) {
  char *temp_filename;

  temp_filename = ft_create_heredoc_file(redir->file);
  if (!temp_filename)
    return (-1);
  free(redir->file);
  redir->file = temp_filename;
  redir->type = TOKEN_REDIR_IN;
  return (0);
}

static int ft_process_cmd_heredocs(t_cmd *cmd) {
  t_redir *redir;

  redir = cmd->redirs;
  while (redir) {
    if (redir->type == TOKEN_HEREDOC) {
      if (ft_process_heredoc_redir(redir) == -1)
        return (-1);
    }
    redir = redir->next;
  }
  return (0);
}

int ft_preprocess_heredocs(t_cmd *cmds) {
  t_cmd *current;

  current = cmds;
  while (current) {
    if (ft_process_cmd_heredocs(current) == -1)
      return (-1);
    current = current->next;
  }
  return (0);
}

char *ft_create_heredoc_file(char *delimiter) {
  char *content;
  char *temp_filename;
  int fd;

  if (!delimiter || !*delimiter)
    return (NULL);
  content = ft_read_heredoc_input(delimiter);
  if (!content)
    return (NULL);
  temp_filename = ft_create_temp_filename();
  if (!temp_filename) {
    free(content);
    return (NULL);
  }
  fd = open(temp_filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
  if (fd == -1) {
    free(content);
    free(temp_filename);
    return (NULL);
  }
  if (ft_strlen(content) > 0)
    write(fd, content, ft_strlen(content));
  close(fd);
  free(content);
  return (temp_filename);
}
