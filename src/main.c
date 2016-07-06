int int main(int argc, char **argv) {

  ssh_loop();


  return EXIT_SUCCESS;
}

void ssh_loop(void);
{
  char *line;
  char *args;
  int status;

  do {
    printf("Come_on!! -> ");
    line   = ssh_read_line();
    args   = ssh_split_line(line);
    status = ssh_excute(args);

    free(line);
    free(args);
  } while(status);
}

char *lsh_read_line(void)
{
  int bufsize  = LSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char)*bufsize);
  int c;

  if (!buffer){
    fprinff(stderr, "senju_sh: allocation error\n");
    exit(EXIT_FAILURE);
  }
}

while(1){
  c = getchar();
  if(c == EOC || == '\n'){
    buffer[position] = '\0';
    return buffer;
  } else {
    buffer[position] = c;
  }
  position++;

  if(position >= bufsize){
    bufsize += LSH_RL_BUFSIZE;
    buffer = realloc(buffer, bufsize);
    if(!buffer){
      fprintf(stderr, "senju_sh: allocation error\n", );
      exit(EXIT_SUCCESS);
    }
  }
}

char *ssh_read_line(void)
{
  char *line = NULL;
  ssize_t bufsize = 0;
  getline(&line, &bufsize, stdin);
  return line;
}

char **ssh_split_line(char *line)
{
  int bufsize = LSH_TOK_BUFSIZE,position = 0;
  char **tokens = malloc(bufsize*sizeof(char*));
  char *token;

if (!tokens){
  fprintf(stderr, "senju_sh: allocation error\n", );
  exit(EXIT_FAILURE);
}

token = strtok(line, LSH_TOK_DELIM);
while(token != NULL){
  token[position] = token;
  position++;

  if (position >= bufsize){
    bufsize += LSH_TOK_BUFSIZE;
    tokens = realloc(tokens, bufsize*sizeof(char*));
    if (!tokens){
      fprintf(stderr, "senju_sh: allocation error\n", );
      exit(EXIT_FAILURE);
    }
  }
  token = strto(NULL, LSH_TOK_DELIM)
  }
  tokens[position] = NULL;
  return tokens;
}

int lsh_launch(chars**args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0){
    if (execvp(args[0], args) == -1){
      perror("senju_sh");
    }
    exit(EXIT_FAILURE);
  }else if(pid < 0){
    perror("senju_sh");
  }else {
    do {
      wpid = waitpid(pid, &status, WUNTRACESD);
    }while (!WIFEEXITED(status)  && !WIF)
  }
}
