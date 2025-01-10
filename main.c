#include <stdio.h>
#include <string.h>


typedef struct Dia{

  char manha[17];
  char tarde[17];
  char noite[17];

} Dia;

void abrirPlano(Dia semana[]){
  FILE *fp = fopen("planosemanal.txt", "r");

  if(fp == NULL){
  printf("Erro ao abrir o arquivo! Criando arquivo....\n");
  return;
  }
  char buffer[17];
  for(int i = 0;i < 7; i++){
  fgets(buffer, sizeof(buffer), fp);
  buffer[strcspn(buffer,"\n")] = '\0';
   fgets(semana[i].manha, sizeof(semana[i].manha), fp);
    semana[i].manha[strcspn(semana[i].manha, "\n")] = '\0';
    fgets(semana[i].tarde, sizeof(semana[i].tarde), fp);
    semana[i].tarde[strcspn(semana[i].tarde, "\n")] = '\0';
    fgets(semana[i].noite, sizeof(semana[i].noite), fp);
    semana[i].noite[strcspn(semana[i].noite, "\n")] = '\0';
  }
  fclose(fp);
}

void salvarPlano(Dia semana[]){
  FILE *fp = fopen("planosemanal.txt", "w");
  char *dias[] = {"Domingo","Segunda", "Terça  ", "Quarta", "Quinta", "Sexta", "Sabado"};
  
  for(int i = 0; i < 7; i++){
    fprintf(fp, "%s\n%s\n%s\n%s\n",dias[i], 
            semana[i].manha, semana[i].tarde, semana[i].noite);
  }
  fclose(fp);
}

void adicionar(Dia semana[]){
  int dia, periodo;
  char atividade[17];
  char *periodos[] = {"manha", "tarde", "noite"};
  
  printf("Escolha um dia para adicionar: \n");
  printf("1. Domingo\n2. Segunda\n3. Terça\n4. Quarta\n");
  printf("5. Quinta\n6. Sexta\n7. Sabado\n");
  scanf("%d", &dia);

    while(dia < 1 || dia > 7){
    printf("Dia inválido, tente novamente!\n");
    scanf("%d", &dia);
  }

  dia--;
  
  
  printf("Escolha o periodo:");
  printf("1. Manha, 2. Tarde, 3. Noite\n");
  scanf("%d", &periodo);
   
  while(periodo < 0 || periodo > 3){
    printf("Periodo inválido, tente novamente...");
    scanf("%d", &periodo);
  }
  
 
  periodo--;

  
  printf("Digite a atividade para %s: \n", periodos[periodo]);
  getchar();
  fgets(atividade, 17, stdin);
  atividade[strcspn(atividade, "\n")] = 0;

  switch (periodo) {
  case 0: strcpy(semana[dia].manha, atividade); break;
  case 1: strcpy(semana[dia].tarde,atividade);break;
  case 2: strcpy(semana[dia].noite, atividade);break;

  }
  printf("\nTarefa adicionada!\n\n");
}


void remover(Dia semana[]){
 int dia, periodo;
  char *periodos[] = {"manha", "tarde", "noite"};
  
  printf("Escolha um dia para remover: \n");
  printf("1. Domingo\n2. Segunda\n3. Terça\n4. Quarta\n");
  printf("5. Quinta\n6. Sexta\n7. Sabado\n");
  scanf("%d", &dia);

  while(dia < 1 || dia > 7){
   printf("Dia inválido, tente novamente...\n");
   scanf("%d", &dia);
 }

  dia--;
  
  
  printf("Escolha o periodo:");
  printf("1. Manha, 2. Tarde, 3. Noite\n");
  scanf("%d", &periodo);

  while(periodo < 0 || periodo > 3){
   printf("Periodo inválido, tente novamente...");
   scanf("%d", &periodo);
  }
 
  periodo--;
  
  switch (periodo) {

    case 0: strcpy(semana[dia].manha,""); break;
    case 1: strcpy(semana[dia].tarde,"");break;
    case 2: strcpy(semana[dia].noite,""); break;

  }
  printf("\n\nAtividade removida!\n\n");
}

void exibir(Dia semana[]){
  char *dias[] = {"Domingo","Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};

 printf(" Dia     |      Manhã     |     Tarde      |     Noite\n");
 printf("---------|----------------|----------------|-------------\n");
  for (int i = 0; i < 7; i++) {
  printf("%-9s|%-16s|%-16s|%-16s\n",
         dias[i], semana[i].manha, semana[i].tarde, semana[i].noite); 
  }
}

int main(){
  Dia semana[7] = {{0}}; 
  int opc;
  abrirPlano(semana);
  

  while(opc != 4){
  printf("=======Week Planner========\n");
  printf("1. Adicionar atividade:\n");
  printf("2. Remover atividade: \n");
  printf("3. Exibir plano semanal: \n");
  printf("4. Sair...\n");
  printf("Escolha uma opção: \n");

  scanf("%d", &opc);

  switch(opc){
    case 1: 
      adicionar(semana);
      salvarPlano(semana);
      break;
    case 2: 
     remover(semana);
     salvarPlano(semana);
     break;
    case 3: 
      exibir(semana);
      salvarPlano(semana);
      break;
    case 4:
      salvarPlano(semana);
      printf("Saindo...\n");
      return 0;
      break;
    default: 
      printf("Opcão inválida, tente novamente! \n");
      break;
    }
    }
  




  return 0;
}
