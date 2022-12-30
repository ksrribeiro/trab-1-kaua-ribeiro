
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// structs
typedef struct {
  char nome[61];
  char sigla[7];
  int num;
  int qtdcandidatos;
  int somatorioidade;
  int somatorionaoh;
  float qtd_votose;
  float qtd_votosf;
  float qtd_votos;
  int votose;
  int votosf;

} tpartido;
typedef struct {
  char nome[61];
  char sexo;
  int idade;
  char cargo;
  int numero;
  char partido[7];
  char nomepartido[61];
  int qtdvotos;
} tcandidato;
typedef struct {
  char nome[61];
  char id[7];
  int votou;
} teleitores;

// cabeçalho das funções
// preencher
int preencheessamerda(tcandidato candidato[320], tcandidato presidentes[10],
                      tcandidato governadores[10], tcandidato federais[150],
                      tcandidato estaduais[150], int qtd_partidos,
                      tpartido partido[10], int contadors[4],
                      char claudio[100]);
int preenchecabresto(teleitores eleitrores[1000], char claudio[100]);
int preencheevilcorp(tpartido partido[10], char claudio[100]);

// menus
void menuprincipal() {
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=\n");
  printf("                    SAUDACOES INVOCADOR\n");
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=\n");
  printf("# Instruções para votar:\n");
  printf("-- Digite o número do candidato para votar\n");
  printf("-- Aperte b ou B para votar em BRANCO\n\n");
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=\n");
  printf("- Digite seu ID para iniciar:");
};
void menufederal() {
  system("clear");
  printf("########################################################\n");
  printf("################# votos impressos ######################\n");
  printf("########################################################\n");
  printf("- VOTE PARA LADRÃO FEDERAL:");
};
void menugov() {
  printf("########################################################\n");
  printf("################# votos impressos ######################\n");
  printf("########################################################\n");
  printf("- VOTE PARA LADRÃO GOVERNADOR:");
};
void menuestadual() {
  printf("########################################################\n");
  printf("################# votos impressos ######################\n");
  printf("########################################################\n");
  printf("- VOTE PARA LADRÃO ESTADUAL:");
};
void menupresidencial() {
  printf("########################################################\n");
  printf("################# votos impressos ######################\n");
  printf("########################################################\n");
  printf("- VOTE PARA LADRÃO MESTRE:");
};
void menubranco() {
  printf("########################################################\n");
  printf("################# URNA ELETRONICA ######################\n");
  printf("########################################################\n");
  printf("- Você está votando em BRANCO\n");
  printf("- Confirmar (c ou C) ou Corrigir (r ou R)?");
};
void menuconfirmacao(tcandidato sla[150], int contador) {
  char c;
  printf("#####################################################"
         "###\n");
  printf("################# URNA ELETRONICA "
         "######################\n");
  printf("#####################################################"
         "###\n");
  printf("- Você está votando em:\n");
  printf("- Nome: %s\n", sla[contador].nome);
  printf("- PARTIDO: %s (%s)\n", sla[contador].nomepartido,
         sla[contador].partido);
  printf("- Confirmar (c ou C) ou Corrigir (r ou R)?");
};
void menunulo() {
  printf("########################################################\n");
  printf("################# URNA ELETRONICA ######################\n");
  printf("########################################################\n");
  printf("- Você está votando em NULO\n");
  printf("- Confirmar (c ou C) ou Corrigir (r ou R)?\n");
};
void menunovamente() {
  printf("#####################################################"
         "###\n");
  printf("################# URNA ELETRONICA "
         "######################\n");
  printf("#####################################################"
         "###\n");
  printf("- VOTO REGISTRADO COM SUCESSO\n");
  printf("- Deseja registrar um novo voto (n ou N) ou finalizar (f ou F) a "
         "votação?");
};
int conrfirma(char c) {
  switch (c) {
  case ('c'): {
    return 1;
    break;
  }
  case ('C'): {
    return 1;
    break;
  }

  case ('R'): {
    return 0;
    break;
  }

  case ('r'): {
    return 0;
    break;
  }
  }
};
int denovo(char c) {
  switch (c) {
  case ('f'): {
    return 1;
    break;
  }
  case ('F'): {
    return 1;
    break;
  }

  case ('n'): {
    return 0;
    break;
  }

  case ('N'): {
    return 0;
    break;
  }
  }
};

// verificações e computar voto
void computavoto(tcandidato candidato[150], tpartido partido[10],
                 int qtdpartidos, int conte) {
  int contpartido = 0;
  // computa voto para o candidato
  candidato[conte].qtdvotos++;
  for (contpartido = 0; contpartido <= qtdpartidos; contpartido++) {
    if (strcmp(candidato[conte].partido, partido[contpartido].sigla) == 0) {
      partido[contpartido].qtd_votos++;
      break;
    }
  }
};
void computavotoe(tcandidato candidato[150], tpartido partido[10],
                  int qtdpartidos, int conte) {
  int contpartido = 0;
  // computa voto para o candidato
  candidato[conte].qtdvotos++;
  for (contpartido = 0; contpartido <= qtdpartidos; contpartido++) {
    if (strcmp(candidato[conte].partido, partido[contpartido].sigla) == 0) {
      partido[contpartido].qtd_votose++;
      break;
    }
  }
};
void computavotof(tcandidato candidato[150], tpartido partido[10],
                  int qtdpartidos, int conte) {
  int contpartido = 0;
  // computa voto para o candidato
  candidato[conte].qtdvotos++;
  for (contpartido = 0; contpartido <= qtdpartidos; contpartido++) {
    if (strcmp(candidato[conte].partido, partido[contpartido].sigla) == 0) {
      partido[contpartido].qtd_votosf++;
      break;
    }
  }
};
int verificaid(teleitores eleitores[1000], int qtd_eleitores, char id[7]) {
  int j = 0;
  // verifica se o id pertence
  for (j = 0; j <= qtd_eleitores; j++) {
    if (strcmp(id, eleitores[j].id) == 0) {
      // id pertence a alguem
      if (eleitores[j].votou == 0) {
        eleitores[j].votou = 1;
        return 1;
      }
    }
  }
  // id invalido
  return 0;
};
int verificavotod(char voto[6], tcandidato estaduais[150], int qtdeleitores,
                  tpartido partido[10], teleitores eleitores[1000],
                  int contadores[4], int qtdpartidos) {
  int num;
  int conte;
  if (voto[0] == 'b' || voto[0] == 'B') {
    return 1500;
  }
  num = atoi(voto);
  for (conte = 0; conte <= contadores[0]; conte++) {
    if (num == estaduais[conte].numero) {
      return conte;
    }
  }
  return 2000;
};
int verificavotof(char voto[6], tcandidato estaduais[150], int qtdeleitores,
                  tpartido partido[10], teleitores eleitores[1000],
                  int contadores[4], int qtdpartidos) {
  int num;
  int conte;
  if (voto[0] == 'b' || voto[0] == 'B') {
    return 1500;
  }
  num = atoi(voto);
  for (conte = 0; conte <= contadores[1]; conte++) {
    if (num == estaduais[conte].numero) {
      return conte;
    }
  }
  return 2000;
};
int verificavotog(char voto[6], tcandidato estaduais[150], int qtdeleitores,
                  tpartido partido[10], teleitores eleitores[1000],
                  int contadores[4], int qtdpartidos) {
  int num;
  int conte;
  if (voto[0] == 'b' || voto[0] == 'B') {
    return 1500;
  }
  num = atoi(voto);
  for (conte = 0; conte <= contadores[2]; conte++) {
    if (num == estaduais[conte].numero) {
      return conte;
    }
  }
  return 2000;
};
int verificavotop(char voto[6], tcandidato estaduais[150], int qtdeleitores,
                  tpartido partido[10], teleitores eleitores[1000],
                  int contadores[4], int qtdpartidos) {
  int num;
  int conte;
  if (voto[0] == 'b' || voto[0] == 'B') {
    return 1500;
  }
  num = atoi(voto);
  for (conte = 0; conte <= contadores[3]; conte++) {
    if (num == estaduais[conte].numero) {
      return conte;
    }
  }
  return 2000;
};
int votacao(tcandidato presidentes[10], tcandidato governadores[10],
            tcandidato federais[150], tcandidato estaduais[150],
            int qtdeleitores, tpartido partido[10], teleitores eleitores[1000],
            int contadores[4], int qtdpartidos, int brancosenulo[4],
            int validos[4]);

// organização de dados com bubblesort
void trocar(tcandidato sla[], int x, int y) {

  tcandidato aux = sla[x];
  sla[x] = sla[y];
  sla[y] = aux;
}
void trocarp(tpartido sla[], int x, int y) {

  tpartido aux = sla[x];
  sla[x] = sla[y];
  sla[y] = aux;
}

void bubbleSort(tcandidato sla[], int contadores) {

  int i, j, k = 0;

  for (i = contadores - 1; i > 0; i--) {
    for (j = 0; j < i; j++) {

      if (sla[j].qtdvotos > sla[j + 1].qtdvotos) {

        trocar(sla, j, j + 1);
      }
      if (sla[j].qtdvotos == sla[j + 1].qtdvotos) {
        k = 0;
        k = strcmp(sla[j].nome, sla[j + 1].nome);

        if (k < 0) {
          trocar(sla, j, j + 1);
        }
      }
    }
  }
}

void bubbleSortpe(tpartido part[10], int qtd_votos) {

  int i, j;

  for (i = qtd_votos - 1; i > 0; i--) {
    for (j = 0; j <= i; j++) {

      if (part[j].qtd_votose > part[j + 1].qtd_votose)

        trocarp(part, j, j + 1);
    }
  }
}
void bubbleSortpf(tpartido part[10], int qtd_votos) {

  int i, j;

  for (i = qtd_votos - 1; i > 0; i--) {
    for (j = 0; j <= i; j++) {

      if (part[j].qtd_votosf > part[j + 1].qtd_votosf)

        trocarp(part, j, j + 1);
    }
  }
}

// distribui as vagas
void distribuivaga(tpartido partido[10], int qtd_partidos, int contadores[4],char jorge[100]) {
  int k;
  float votostotais = 0;
  float porcentagem = 0;
  float mediaidade1 = 0, mediaidade2 = 0;
  float qtdneutre1, qtdneutre2;
  int votosdisponiveis = 10;
  for (k = 0; k <= qtd_partidos; k++) {
    votostotais = votostotais + partido[k].qtd_votose;
  }
  char claudio2[100];
  strcpy(claudio2, jorge);
  strcat(claudio2, "/bancada_deputado_estadual.csv");
  FILE *bancada = fopen(claudio2, "w");
  fprintf(bancada, "Partido,Eleitos");
  for (k = qtd_partidos; k >= 0; k--) {
    fprintf(bancada, "\n");
    porcentagem = partido[k].qtd_votose * 100 / votostotais;
    porcentagem = (porcentagem * 10) / 100;
    porcentagem = round(porcentagem);
    fprintf(bancada, "%s,%.f", partido[k].sigla, porcentagem);

    if (porcentagem < votosdisponiveis) {
      partido[k].votose = porcentagem;
      votosdisponiveis = votosdisponiveis - porcentagem;
    } else if (porcentagem >= votosdisponiveis && k != 0 &&
               (partido[k].qtd_votose == partido[k - 1].qtd_votose)) {
      if (partido[k].qtd_votose == partido[k - 1].qtd_votose) {
        mediaidade1 = partido[k].somatorioidade / partido[k].qtdcandidatos;
        mediaidade2 =
            partido[k - 1].somatorioidade / partido[k - 1].qtdcandidatos;
        if (mediaidade1 > mediaidade2) {
          partido[k].votose = votosdisponiveis;
          break;
        } else if (mediaidade1 < mediaidade2) {
          partido[k - 1].votose = votosdisponiveis;
          break;
        } else if (mediaidade1 == mediaidade2) {
          if (partido[k].somatorionaoh > partido[k - 1].somatorionaoh) {
            partido[k].votose = votosdisponiveis;
            break;
          } else if (partido[k].somatorionaoh < partido[k - 1].somatorionaoh) {
            partido[k - 1].votose = votosdisponiveis;
            break;
          }
        }
      }
    } else {
      partido[k].votose = votosdisponiveis;
      break;
    }
  }
  fclose(bancada);
};
void distribuivagaf(tpartido partido[10], int qtd_partidos, int contadores[4],char jorge[100]) {
  int k;
  float votostotais = 0;
  float porcentagem = 0;
  float mediaidade1 = 0, mediaidade2 = 0;
  float qtdneutre1, qtdneutre2;
  int votosdisponiveis = 5;
  for (k = 0; k <= qtd_partidos; k++) {
    votostotais = votostotais + partido[k].qtd_votosf;
  }
  char claudio2[100];
  strcpy(claudio2, jorge);
  strcat(claudio2, "/bancada_deputado_federal.csv");

  FILE *bancada = fopen(claudio2, "w");
  fprintf(bancada, "Partido,Eleitos");
  for (k = qtd_partidos; k >= 0; k--) {
    fprintf(bancada, "\n");
    porcentagem = partido[k].qtd_votosf * 100 / votostotais;
    porcentagem = (porcentagem * 5) / 100;
    porcentagem = round(porcentagem);
    fprintf(bancada, "%s,%.f", partido[k].sigla, porcentagem);

    if (porcentagem < votosdisponiveis) {
      partido[k].votosf = porcentagem;
      votosdisponiveis = votosdisponiveis - porcentagem;
    } else if (porcentagem >= votosdisponiveis && k != 0 &&
               (partido[k].qtd_votosf == partido[k - 1].qtd_votosf)) {
      if (partido[k].qtd_votosf == partido[k - 1].qtd_votosf) {
        mediaidade1 = partido[k].somatorioidade / partido[k].qtdcandidatos;
        mediaidade2 =
            partido[k - 1].somatorioidade / partido[k - 1].qtdcandidatos;
        if (mediaidade1 > mediaidade2) {
          partido[k].votosf = votosdisponiveis;
          break;
        } else if (mediaidade1 < mediaidade2) {
          partido[k - 1].votosf = votosdisponiveis;
          break;
        } else if (mediaidade1 == mediaidade2) {
          if (partido[k].somatorionaoh > partido[k - 1].somatorionaoh) {
            partido[k].votosf = votosdisponiveis;
            break;
          } else if (partido[k].somatorionaoh < partido[k - 1].somatorionaoh) {
            partido[k - 1].votosf = votosdisponiveis;
            break;
          }
        }
      }
    } else {
      partido[k].votosf = votosdisponiveis;
      break;
    }
  }
  fclose(bancada);
};

// cria o ranking's
void maiusculo(char s1[], char s2[]) {
  int i = 0;
  while (s1[i] != '\0') {
    s2[i] = toupper(s1[i]);
    i++;
  }
  s2[i] = '\0';
}

// imprime tudo
void rankingpresidentes(tcandidato presidentes[10], int validos[4],
                        int contadores[4], char jorge[100]) {
  int i = 0;
  float votosc, votost;
  float percentual = 0;
  char nome[61];
  char claudio2[100];
  strcpy(claudio2, jorge);
  strcat(claudio2, "/ranking_presidente.csv");
  FILE *presidente = fopen(claudio2, "w");
  fprintf(presidente, "NOME,PARTIDO,VOTOS,PERCENTUAL");
  for (i = contadores[3] - 1; i >= 0; i--) {
    fprintf(presidente, "\n");
    votosc = presidentes[i].qtdvotos;
    votost = validos[3];
    percentual = (votosc * 100) / votost;
    maiusculo(presidentes[i].nome, nome);
    fprintf(presidente, "%s,%s,%d,%.2f%%", nome, presidentes[i].partido,
            presidentes[i].qtdvotos, percentual);
  }
  fclose(presidente);
};
void rankinggovernadores(tcandidato governadores[10], int validos[4],
                         int contadores[4], char jorge[100]) {
  int i = 0;
  float votosc, votost;
  float percentual = 0;
  char nome[61];
  char claudio2[100];
  strcpy(claudio2, jorge);
  strcat(claudio2, "/ranking_governador.csv");
  FILE *governador = fopen(claudio2, "w");
  fprintf(governador, "NOME,PARTIDO,VOTOS,PERCENTUAL");
  for (i = contadores[2] - 1; i >= 0; i--) {
    fprintf(governador, "\n");
    votosc = governadores[i].qtdvotos;
    votost = validos[2];
    percentual = (votosc * 100) / votost;
    maiusculo(governadores[i].nome, nome);
    fprintf(governador, "%s,%s,%d,%.2f%%", nome, governadores[i].partido,
            governadores[i].qtdvotos, percentual);
  }
  fclose(governador);
};
void rankingfederais(tcandidato governadores[150], int validos[4],
                     int contadores[4], char jorge[100]) {
  int i = 0;
  float votosc, votost;
  float percentual = 0;
  char nome[61];
  char claudio2[100];
  strcpy(claudio2, jorge);
  strcat(claudio2, "/ranking_deputado_federal.csv");
  FILE *governador = fopen(claudio2, "w");
  fprintf(governador, "NOME,PARTIDO,VOTOS,PERCENTUAL");
  for (i = contadores[1] - 1; i >= 0; i--) {
    fprintf(governador, "\n");
    votosc = governadores[i].qtdvotos;
    votost = validos[1];
    percentual = (votosc * 100) / votost;
    maiusculo(governadores[i].nome, nome);
    fprintf(governador, "%s,%s,%d,%.2f%%", nome, governadores[i].partido,
            governadores[i].qtdvotos, percentual);
  }
  fclose(governador);
};
void rankingestaduais(tcandidato governadores[150], int validos[4],
                      int contadores[4], char jorge[100]) {
  int i = 0;
  float votosc, votost;
  float percentual = 0;
  char nome[61];
  char claudio2[100];
  strcpy(claudio2, jorge);
  strcat(claudio2, "/ranking_deputado_estadual.csv");
  FILE *governador = fopen(claudio2, "w");
  fprintf(governador, "NOME,PARTIDO,VOTOS,PERCENTUAL");
  for (i = contadores[0] - 1; i >= 0; i--) {
    fprintf(governador, "\n");
    votosc = governadores[i].qtdvotos;
    votost = validos[0];
    percentual = (votosc * 100) / votost;
    maiusculo(governadores[i].nome, nome);
    fprintf(governador, "%s,%s,%d,%.2f%%", nome, governadores[i].partido,
            governadores[i].qtdvotos, percentual);
  }
  fclose(governador);
};
void criaeleitos(tcandidato presidentes[10], tcandidato governadores[10],
                 tcandidato federais[150], tcandidato estaduais[150],
                 int qtd_partidos, tcandidato eleitop[1], tcandidato eleitog[1],
                 tcandidato eleitoe[10], tcandidato eleitof[10],
                 int contadores[4], tpartido partido[10], char jorge[100]) {
  char nome[61];
   char claudio2[100];
  strcpy(claudio2, jorge);
  strcat(claudio2, "/eleitos.csv");
  FILE *arq = fopen(claudio2, "w");
  fprintf(arq, "CARGO,NOME,PARTIDO\n");
  eleitop[0] = presidentes[contadores[3] - 1];
  maiusculo(eleitop[0].nome, nome);
  fprintf(arq, "PRESIDENTE,%s,%s\n", nome, eleitop[0].partido);
  eleitog[0] = governadores[contadores[2] - 1];
  maiusculo(eleitog[0].nome, nome);
  fprintf(arq, "GOVERNADOR,%s,%s", nome, eleitog[0].partido);
  int i, j, y = 0, w = 0;

  // cria eleitosf
  for (i = contadores[1]; i >= 0; i--) {
    for (j = 0; j <= qtd_partidos; j++) {
      if (strcmp(federais[i].partido, partido[j].sigla) == 0) {
        if (partido[j].votosf > 0) {
          fprintf(arq, "\n");
          eleitof[y] = federais[i];
          partido[j].votosf--;
          maiusculo(eleitof[y].nome, nome);
          fprintf(arq, "DEPUTADO FEDERAL,%s,%s", nome, eleitof[y].partido);
          y++;
        }
      }
    }
  }
  printf("\n");
  bubbleSortpe(partido, qtd_partidos);
  // cria eleitose
  for (i = contadores[0]; i >= 0; i--) {
    for (j = 0; j <= qtd_partidos; j++) {
      if (strcmp(estaduais[i].partido, partido[j].sigla) == 0) {
        if (partido[j].votose > 0) {
          fprintf(arq, "\n");
          eleitoe[w] = estaduais[i];
          partido[j].votose--;
          maiusculo(eleitoe[w].nome, nome);
          fprintf(arq, "DEPUTADO ESTADUAL,%s,%s", nome, eleitoe[w].partido);
          w++;
        }
      }
    }
  }
  fclose(arq);
};
void criamedia(tcandidato eleitop[0], tcandidato eleitog[0],
               tcandidato eleitof[10], tcandidato eleitoe[10],
               int contadores[4], char jorge[100]) {
  float mediap = 0, mediag = 0;
  float mediae = 0, mediaf = 0, num = 0;
  int i = 0;
  // media de presidente
  mediap = eleitop[0].idade;
  // gov
  mediag = eleitog[0].idade;
  // fed
  num = 0;
  for (i = 4; i >= 0; i--) {
    num = num + eleitof[i].idade;
    mediaf = num / 5;
  }
  // est
  num = 0;
  for (i = 9; i >= 0; i--) {
    num = num + eleitoe[i].idade;
    mediae = num / 10;
  }
   char claudio2[100];
  strcpy(claudio2, jorge);
  strcat(claudio2, "/media_idade.csv");
  FILE *media = fopen(claudio2, "w");
  fprintf(media, "CARGO,MEDIA\n");
  fprintf(media, "DEPUTADO ESTADUAL,%.2f\n", mediae);
  fprintf(media, "DEPUTADO FEDERAL,%.2f\n", mediaf);
  fprintf(media, "GOVERNADOR,%.2f\n", mediag);
  fprintf(media, "PRESIDENTE,%.2f", mediap);
  fclose(media);
};
int qualsexo(char c) {
  switch (c) {
  case ('M'): {
    return 3;
    ;
    break;
  }
  case ('F'): {
    return 4;
    break;
  }
  case ('O'): {
    return 5;
    break;
  }
  }
};

void criagenerofluido(tcandidato eleitof[10], tcandidato eleitoe[10],
                      int contadores[4], char jorge[100]) {
  int cont = 0, num, i, m = 0, f = 0, o = 0;
  float mediaf, mediam, mediao, total;
  int c;

  // fed

  for (i = 4; i >= 0; i--) {
    c = qualsexo(eleitof[i].sexo);

    switch (c) {
    case (3): {
      m++;
      break;
    }
    case (4): {
      f++;
      break;
    }
    case (5): {
      o++;
      break;
    }
    }
  }
  // est

  for (i = 9; i >= 0; i--) {
    c = qualsexo(eleitof[i].sexo);
    switch (c) {
    case (3): {
      m++;
      break;
    }
    case (4): {
      f++;
      break;
    }
    case (5): {
      o++;
      break;
    }
    }
  }
  total = m + f + o;
  mediam = m * 100 / total;
  mediaf = f * 100 / total;
  mediao = o * 100 / total;
   char claudio2[100];
  strcpy(claudio2, jorge);
  strcat(claudio2, "/genero_legislativo.csv");
  FILE *media = fopen(claudio2, "w");
  fprintf(media, "GENERO,PERCENTUAL\n");
  fprintf(media, "M,%.2f\n", mediam);
  fprintf(media, "F,%.2f\n", mediaf);
  fprintf(media, "O,%.2f\n", mediao);
  fclose(media);
};
void criaboletim(tcandidato presidentes[10], tcandidato governadores[1],
                 tcandidato federais[150], tcandidato estaduais[150],
                 int validos[4], int brancosenulos[4],
                 teleitores eleitores[1000], int qtd_eleitores,
                 int contadores[4], char jorge[100]) {
  int i;
  float num, per, totalp = 0;
  int bp = 0, bg = 0, bf = 0, be = 0;
  float cbp = 0, cbg = 0, cbf = 0, cbe = 0;
  int presentes = 0, faltaram = 0;
  float cp, cf;
  float perp = 0, perf = 0;

  float perbp, perbg, perbf, perbe;
  char nome[61];
  int contp = 0, contg = 0, contf = 0, conte = 0;

  for (i = 0; i < qtd_eleitores; i++) {
    if (eleitores[i].votou == 1) {
      presentes++;
    } else if (eleitores[i].votou == 0) {
      faltaram++;
    }
  }

  totalp = presentes;
   char claudio2[100];
  strcpy(claudio2, jorge);
  strcat(claudio2, "/boletim.csv");
  FILE *boletim = fopen(claudio2, "w");
  fprintf(boletim, "CANDIDATO,PARTIDO,VOTOS\n");
  // presidentes
  for (i = 0; i < contadores[3]; i++) {
    maiusculo(presidentes[i].nome, nome);
    num = presidentes[i].qtdvotos;
    contp = contp + presidentes[i].qtdvotos;
    per = (num * 100) / totalp;
    fprintf(boletim, "%s,%s,%d(%.2f%%)\n", nome, presidentes[i].partido,
            presidentes[i].qtdvotos, per);
  }
  bp = presentes - contp;
  cbp = bp;
  perbp = (cbp * 100 / totalp);
  fprintf(boletim, "BRANCOS E NULOS,-,%d(%.2f%%)\n", bp, perbp);
  fprintf(boletim, "-,-,-\n");
  // gov
  for (i = 0; i < contadores[2]; i++) {
    maiusculo(governadores[i].nome, nome);
    num = governadores[i].qtdvotos;
    contg = contg + governadores[i].qtdvotos;
    per = (num * 100) / totalp;
    fprintf(boletim, "%s,%s,%d(%.2f%%)\n", nome, governadores[i].partido,
            governadores[i].qtdvotos, per);
  }
  bg = presentes - contg;
  cbg = bg;
  perbg = (cbg * 100 / totalp);
  fprintf(boletim, "BRANCOS E NULOS,-,%d(%.2f%%)\n", bg, perbg);
  fprintf(boletim, "-,-,-\n");

  // df
  for (i = 0; i < contadores[1]; i++) {
    maiusculo(federais[i].nome, nome);
    num = federais[i].qtdvotos;
    contf = contf + federais[i].qtdvotos;
    per = (num * 100) / totalp;
    fprintf(boletim, "%s,%s,%d(%.2f%%)\n", nome, federais[i].partido,
            federais[i].qtdvotos, per);
  }
  bf = presentes - contf;
  cbf = bf;
  perbf = (cbf * 100 / totalp);
  fprintf(boletim, "BRANCOS E NULOS,-,%d(%.2f%%)\n", bf, perbf);
  fprintf(boletim, "-,-,-\n");

  // de
  for (i = 0; i < contadores[0]; i++) {
    maiusculo(estaduais[i].nome, nome);
    num = estaduais[i].qtdvotos;
    conte = conte + estaduais[i].qtdvotos;
    per = (num * 100) / totalp;
    fprintf(boletim, "%s,%s,%d(%.2f%%)\n", nome, estaduais[i].partido,
            estaduais[i].qtdvotos, per);
  }
  be = presentes - conte;
  cbe = be;
  perbe = (cbe * 100 / totalp);
  fprintf(boletim, "BRANCOS E NULOS,-,%d(%.2f%%)\n", be, perbe);
  fprintf(boletim, "-,-,-\n");
  cp = presentes;
  cf = faltaram;
  perp = (presentes * 100) / qtd_eleitores;
  perf = (faltaram * 100) / qtd_eleitores;
  fprintf(boletim, "TOTAL DE ELEITORES,-,%d(100%%)\n", qtd_eleitores);
  fprintf(boletim, "ELEITORES PRESENTES,-,%d(%.2f%%)\n", presentes, perp);
  fprintf(boletim, "ELEITORES AUSENTES,-,%d(%.2f%%)", faltaram, perf);

  fclose(boletim);
};
// main
int main(int argc, char *argv[]) {
  // obs: tirei um int i, se der merda colcoa de novo e inicia como 1
  int qtd_candidatos, qtd_eleitores, qtd_partidos;
  tcandidato candidato[320], presidentes[10], governadores[10], federais[150],
      eleitop[1], eleitog[1], eleitoe[10], eleitof[10], estaduais[150];
  teleitores eleitores[1000];
  tpartido partido[10];
  int contadores[4];
  // saida
  char jorge[100];
  strcpy(jorge, argv[2]);
  // entrada
  char claudio[100];
  strcpy(claudio, argv[1]);
  /*presidente=3
    gov=2
    federal=1
    estadual=0*/
  int brancosenulo[4] = {0, 0, 0, 0};
  int validos[4] = {0, 0, 0, 0};

  // preenche os partidos

  qtd_partidos = preencheevilcorp(partido, claudio);

  // parte responsavel por preencher a struct de candidatos

  qtd_candidatos =
      preencheessamerda(candidato, presidentes, governadores, federais,
                        estaduais, qtd_partidos, partido, contadores, claudio);

  // preenche os burros (eleitores)

  qtd_eleitores = preenchecabresto(eleitores, claudio);

  votacao(presidentes, governadores, federais, estaduais, qtd_eleitores,
          partido, eleitores, contadores, qtd_partidos, brancosenulo, validos);
  criaboletim(presidentes, governadores, federais, estaduais, validos,
              brancosenulo, eleitores, qtd_eleitores, contadores, jorge);

  // ordena em ordem crescente por quantidade de votos
  bubbleSort(presidentes, contadores[3]);
  bubbleSort(governadores, contadores[2]);
  bubbleSort(federais, contadores[1]);
  bubbleSort(estaduais, contadores[0]);

  // o nome das funções é autoexplicativo
  bubbleSortpe(partido, qtd_partidos);
  distribuivaga(partido, qtd_partidos, contadores, jorge);
  bubbleSortpf(partido, qtd_partidos);
  distribuivagaf(partido, qtd_partidos, contadores, jorge);
  rankingpresidentes(presidentes, validos, contadores, jorge);
  rankinggovernadores(governadores, validos, contadores, jorge);
  rankingfederais(federais, validos, contadores, jorge);
  rankingestaduais(estaduais, validos, contadores, jorge);
  criaeleitos(presidentes, governadores, federais, estaduais, qtd_partidos,
              eleitop, eleitog, eleitoe, eleitof, contadores, partido, jorge);
  criamedia(eleitop, eleitog, eleitof, eleitoe, contadores, jorge);
  criagenerofluido(eleitof, eleitoe, contadores, jorge);

  return 0;
}
// preenche os candidatos alem de separar quais estão aptos a votar
int preencheessamerda(tcandidato candidato[320], tcandidato presidentes[10],
                      tcandidato governadores[10], tcandidato federais[150],
                      tcandidato estaduais[150], int qtd_partidos,
                      tpartido partido[10], int contadores[4],
                      char claudio[100]) {
  int i = 0, j = 0;
  char claudio2[100];
  strcpy(claudio2, claudio);
  strcat(claudio2, "/candidatos.csv");
  FILE *arq = fopen(claudio2, "r");
  while (1) {
    if (fgetc(arq) == '\n') {

      break;
    }
  }
  // contadores
  int cp = 0, cg = 0, cf = 0, ce = 0;

  int numerocortado;
  char nome;
  while (1) {
    // obs:coloquei os if's pra tirar os warning's
    if (fscanf(arq, "%[^,],%c,", candidato[i].nome, &candidato[i].sexo)) {
    }
    if (fscanf(arq, "%d,", &candidato[i].idade)) {
    }
    if (fscanf(arq, "%c,", &candidato[i].cargo)) {
    }
    if (fscanf(arq, "%d,", &candidato[i].numero)) {
    }
    if (fscanf(arq, "%[^\n]\n", candidato[i].partido)) {
    }
    // incializa qtd de votos para n dar erro
    candidato[i].qtdvotos = 0;

    // verifica aptdão
    for (j = 0; j <= qtd_partidos; j++) {
      // tem partido
      if (strcmp(candidato[i].partido, partido[j].sigla) == 0) {
        partido[j].qtdcandidatos++;
        if (candidato[i].sexo == 'M') {
        } else {
          partido[j].somatorionaoh++;
        }
        partido[j].somatorioidade =
            partido[i].somatorioidade + candidato[i].idade;

        switch (candidato[i].cargo) {
        case ('P'): {
          numerocortado = candidato[i].numero;
          if (numerocortado == partido[j].num) {
            if (candidato[i].numero < 100 && candidato[i].numero > 9) {
              // se chegou aqui ta certo
              strcpy(presidentes[cp].nome, candidato[i].nome);
              presidentes[cp].idade = candidato[i].idade;
              presidentes[cp].idade = candidato[i].idade;
              presidentes[cp].sexo = candidato[i].sexo;
              presidentes[cp].numero = candidato[i].numero;
              strcpy(presidentes[cp].partido, candidato[i].partido);
              strcpy(presidentes[cp].nomepartido, partido[j].nome);
              cp++;
              i++;
            }
          }
          break;
        }

        case ('G'): {
          numerocortado = candidato[i].numero;
          if (numerocortado == partido[j].num) {
            if (candidato[i].numero < 100 && candidato[i].numero > 9) {
              // se chegou aqui deu certo
              strcpy(governadores[cg].nome, candidato[i].nome);
              governadores[cg].idade = candidato[i].idade;
              governadores[cg].cargo = candidato[i].cargo;
              governadores[cg].sexo = candidato[i].sexo;
              governadores[cg].numero = candidato[i].numero;
              strcpy(governadores[cg].partido, candidato[i].partido);
              strcpy(governadores[cg].nomepartido, partido[j].nome);

              cg++;
              i++;
            }
          }
          break;
        }

        case ('F'): {
          numerocortado = candidato[i].numero;
          while (numerocortado > 99) {
            numerocortado = numerocortado / 10;
          }
          if (numerocortado == partido[j].num) {
            if (candidato[i].numero < 10000 && candidato[i].numero > 999) {
              // se chegou até aqui deu certo
              strcpy(federais[cf].nome, candidato[i].nome);
              federais[cf].idade = candidato[i].idade;
              federais[cf].sexo = candidato[i].sexo;
              federais[cf].cargo = candidato[i].cargo;
              federais[cf].numero = candidato[i].numero;
              strcpy(federais[cf].partido, candidato[i].partido);
              strcpy(federais[cf].nomepartido, partido[j].nome);
              cf++;
              i++;
            }
          }
          break;
        }

        case ('E'): {
          numerocortado = candidato[i].numero;
          while (numerocortado > 99) {
            numerocortado = numerocortado / 10;
          }
          if (numerocortado == partido[j].num) {
            if (candidato[i].numero < 100000 && candidato[i].numero > 9999) {
              // se chegou até aqui deu certo
              strcpy(estaduais[ce].nome, candidato[i].nome);
              estaduais[ce].idade = candidato[i].idade;
              estaduais[ce].sexo = candidato[i].sexo;
              estaduais[ce].cargo = candidato[i].cargo;
              estaduais[ce].numero = candidato[i].numero;
              strcpy(estaduais[ce].partido, candidato[i].partido);
              strcpy(estaduais[ce].nomepartido, partido[j].nome);

              ce++;
              i++;
            }
          }
          break;
        }

        default:
          break;
        }
      }
    }

    // verifica se secou no final do arquivo para parar o loop
    if (feof(arq)) {
      break;
    }
  }
  contadores[0] = ce;
  contadores[1] = cf;
  contadores[2] = cg;
  contadores[3] = cp;
  fclose(arq);
  return i;
};

// autoexplicativo
int preenchecabresto(teleitores eleitores[], char claudio[100]) {
  int i = 0;
  char claudio2[100];
  strcpy(claudio2, claudio);
  strcat(claudio2, "/eleitores.csv");
  FILE *file = fopen(claudio2, "r");
  while (1) {
    if (fgetc(file) == '\n') {

      break;
    }
  }
  while (1) {
    if (fscanf(file, "%[^,],%s", eleitores[i].nome, eleitores[i].id))
      eleitores[i].votou = 0;
    if (feof(file)) {
      break;
    }
    i++;
  }
  fclose(file);
  return i;
};

// preenche os partidos
int preencheevilcorp(tpartido partido[10], char claudio[100]) {
  int i = 0;
  char claudio2[100];
  strcpy(claudio2, claudio);
  strcat(claudio2, "/partidos.csv");
  FILE *corp = fopen(claudio2, "r");
  while (1) {
    if (fgetc(corp) == '\n') {

      break;
    }
  }
  while (1) {
    if (fscanf(corp, "%[^,],%[^,],%d\n", partido[i].nome, partido[i].sigla,
               &partido[i].num))
      partido[i].qtd_votose = 0;
    partido[i].qtd_votosf = 0;
    partido[i].qtd_votos = 0;
    partido[i].somatorionaoh = 0;
    partido[i].somatorioidade = 0;
    partido[i].qtdcandidatos = 0;
    if (feof(corp)) {
      break;
    }
    i++;
  }
  fclose(corp);
  return i;
};

int votacao(tcandidato presidentes[10], tcandidato governadores[10],
            tcandidato federais[150], tcandidato estaduais[150],
            int qtdeleitores, tpartido partido[10], teleitores eleitores[1000],
            int contadores[4], int qtdpartidos, int brancosenulo[4],
            int validos[4]) {
  char novovoto;
  char id[7];
  char voto[6];
  char c;
  int confirmador = 0, contpartido;
  char idvalido = 0;
  int novamente = 0;
  int verificadorvoto;
  while (novamente == 0) {
    char idvalido = 0;
    while (idvalido == 0) {
      menuprincipal();
      scanf("%s", id);
      scanf("\n");
      idvalido = verificaid(eleitores, qtdeleitores, id);
      system("clear");
    }
    // votação DE
    while (confirmador == 0) {

      system("clear");
      menuestadual();
      scanf("%s", voto);
      scanf("\n");
      verificadorvoto = verificavotod(voto, estaduais, qtdeleitores, partido,
                                      eleitores, contadores, qtdpartidos);
      if (verificadorvoto == 1500) {
        system("clear");
        menubranco();
        scanf("%c", &c);
        scanf("\n");
        confirmador = conrfirma(c);
        if (confirmador == 1) {
          brancosenulo[0]++;
        }
        system("clear");
      } else if (verificadorvoto == 2000) {
        system("clear");
        menunulo();
        scanf("%c", &c);
        scanf("\n");
        confirmador = conrfirma(c);
        if (confirmador == 1) {
          brancosenulo[0]++;
        }
        system("clear");
      } else {
        system("clear");
        menuconfirmacao(estaduais, verificadorvoto);
        scanf("%c", &c);
        scanf("\n");
        confirmador = conrfirma(c);
        if (confirmador == 1) {
          validos[0]++;
          computavotoe(estaduais, partido, qtdpartidos, verificadorvoto);
        }
        system("clear");
      }
    }
    verificadorvoto = 0;
    confirmador = 0;

    // votação DF
    while (confirmador == 0) {

      system("clear");
      menufederal();
      scanf("%s", voto);
      scanf("\n");
      verificadorvoto = verificavotof(voto, federais, qtdeleitores, partido,
                                      eleitores, contadores, qtdpartidos);
      if (verificadorvoto == 1500) {
        system("clear");
        menubranco();
        scanf("%c", &c);
        scanf("\n");
        confirmador = conrfirma(c);
        if (confirmador == 1) {
          brancosenulo[1]++;
        }
        system("clear");
      } else if (verificadorvoto == 2000) {
        system("clear");
        menunulo();
        scanf("%c", &c);
        scanf("\n");
        confirmador = conrfirma(c);
        if (confirmador == 1) {
          brancosenulo[1]++;
        }
        system("clear");
      } else {
        system("clear");
        menuconfirmacao(federais, verificadorvoto);
        scanf("%c", &c);
        scanf("\n");
        confirmador = conrfirma(c);
        if (confirmador == 1) {
          validos[1]++;
          computavotof(federais, partido, qtdpartidos, verificadorvoto);
        }
        system("clear");
      }
    }
    verificadorvoto = 0;
    confirmador = 0;

    // votacao governador
    while (confirmador == 0) {

      system("clear");
      menugov();
      scanf("%s", voto);
      scanf("\n");
      verificadorvoto = verificavotog(voto, governadores, qtdeleitores, partido,
                                      eleitores, contadores, qtdpartidos);
      if (verificadorvoto == 1500) {
        system("clear");
        menubranco();
        scanf("%c", &c);
        scanf("\n");
        confirmador = conrfirma(c);
        if (confirmador == 1) {
          brancosenulo[2]++;
        }
        system("clear");
      } else if (verificadorvoto == 2000) {
        system("clear");
        menunulo();
        scanf("%c", &c);
        scanf("\n");
        confirmador = conrfirma(c);
        if (confirmador == 1) {
          brancosenulo[2]++;
        }
        system("clear");
      } else {
        system("clear");
        menuconfirmacao(governadores, verificadorvoto);
        scanf("%c", &c);
        scanf("\n");
        confirmador = conrfirma(c);
        if (confirmador == 1) {
          validos[2]++;
          computavoto(governadores, partido, qtdpartidos, verificadorvoto);
        }
        system("clear");
      }
    }
    verificadorvoto = 0;
    confirmador = 0;

    // votação presidente
    while (confirmador == 0) {

      system("clear");
      menupresidencial();
      scanf("%s", voto);
      scanf("\n");
      verificadorvoto = verificavotop(voto, presidentes, qtdeleitores, partido,
                                      eleitores, contadores, qtdpartidos);
      if (verificadorvoto == 1500) {
        system("clear");
        menubranco();
        scanf("%c", &c);
        scanf("\n");
        confirmador = conrfirma(c);
        if (confirmador == 1) {
          brancosenulo[3]++;
        }
        system("clear");
      } else if (verificadorvoto == 2000) {
        system("clear");
        menunulo();
        scanf("%c", &c);
        scanf("\n");
        confirmador = conrfirma(c);
        system("clear");
      } else {
        system("clear");
        menuconfirmacao(presidentes, verificadorvoto);
        scanf("%c", &c);
        scanf("\n");
        confirmador = conrfirma(c);
        if (confirmador == 1) {
          brancosenulo[3]++;
        }
        if (confirmador == 1) {
          validos[3]++;
          computavoto(presidentes, partido, qtdpartidos, verificadorvoto);
        }
        system("clear");
      }
    }
    verificadorvoto = 0;
    confirmador = 0;

    // votar de novo?
    menunovamente();
    scanf("%c", &novovoto);
    novamente = denovo(novovoto);
    system("clear");
    scanf("\n");
  }
};
