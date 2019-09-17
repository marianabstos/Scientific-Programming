from Grafo import Grafo
import copy

class BFS:
    def __init__(self, estadoInicial, objetivo):
        self.estadoInicial = estadoInicial #vertice inicial do BFS
        self.objetivo = objetivo #vertice objetivo do BFS
        self.acoes = [] #lista de ações tomadas pelo BFS
        
    def getAcoes(self):
        return self.acoes
    
    #Função que evita do algoritmo sempre expandir para posições opostas
    def trataAcoesRepetidas(self,acaoAtual, ultimasDuasAcoes):
        if len(ultimasDuasAcoes) <2:
            return True
        elif ((ultimasDuasAcoes[0] == 'direita') and (ultimasDuasAcoes[1] == 'esquerda') and (acaoAtual == 'direita')):
            return False
        elif ((ultimasDuasAcoes[0] == 'esquerda') and (ultimasDuasAcoes[1] == 'direita') and (acaoAtual == 'esquerda')):
            return False
        elif ((ultimasDuasAcoes[0] == 'abaixo') and (ultimasDuasAcoes[1] == 'acima') and (acaoAtual == 'abaixo')):
            return False
        elif ((ultimasDuasAcoes[0] == 'acima') and (ultimasDuasAcoes[1] == 'abaixo') and (acaoAtual == 'acima')):
            return False
        else:
            return True
        
    #Função que verifica se o vértice é a solução do quebra-cabeça
    def testeSolucao(self, estadoAtual):
        if self.objetivo == estadoAtual:
            return True
        else:
            return False
    
    #Função onde ocorre o BFS
    def buscaLargura(self):
        visitado = []
        fila = []
        
        g = Grafo(self.estadoInicial)
        fila.append(0)
        visitado.append(0)
        
        while fila:
            vertice = copy.deepcopy(fila.pop(0))
            g.expandir(vertice)

            numFilhos = copy.deepcopy(len(g.getListaAdjacencia()[vertice]))
            custoFilhos = {}
            custoFilhos[0] = []
            custoFilhos[0].append(10000)

            if vertice == 0:
                for i in range(numFilhos):
                    custoFilhos[g.getListaAdjacencia()[vertice][i]] = []
                    custoFilhos[g.getListaAdjacencia()[vertice][i]].append(g.getCusto()[g.getListaAdjacencia()[vertice][i]])
            else:
                for i in range(1,numFilhos):
                    custoFilhos[g.getListaAdjacencia()[vertice][i]] = []
                    custoFilhos[g.getListaAdjacencia()[vertice][i]].append(g.getCusto()[g.getListaAdjacencia()[vertice][i]]) 

            #if self.trataAcoesRepetidas(g.getDirecao()[min(custoFilhos, key=custoFilhos.get)], self.acoes[len(self.acoes)-2:]) == True:
                #verticeMenorCusto = min(custoFilhos, key=custoFilhos.get)
            #else:
                #custoFilhos[min(custoFilhos, key=custoFilhos.get)] = [10000]
                #verticeMenorCusto = min(custoFilhos, key=custoFilhos.get)
            
            custoFilhos[min(custoFilhos, key=custoFilhos.get)] = [10000]
            verticeMenorCusto = min(custoFilhos, key=custoFilhos.get)
            
            if self.testeSolucao(g.getPuzzleStore()[vertice]) == True:
                print("Solução Encontrada")
                print(self.acoes)
                break

            if verticeMenorCusto not in visitado:
                fila.append(verticeMenorCusto)
                self.acoes.append(g.getDirecao()[verticeMenorCusto])
                visitado.append(verticeMenorCusto)
                del custoFilhos
        