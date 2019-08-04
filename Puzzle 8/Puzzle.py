import copy

class Puzzle:
    def __init__(self, pieces):
        self.pieces = pieces
        self.tamanhoVizinhos = 0
        self.vizinhos = []
        self.direcoes = []
        
    def getPieces(self):
        return self.pieces
    
    def getTamanhoVizinhos(self):
        return self.tamanhoVizinhos
    
    def getVizinhos(self):
        return self.vizinhos
    
    def getDirecoes(self):
        return self.direcoes
    
    def swap(self,lista, pos1, pos2):
        aux = lista[pos1]
        lista[pos1] = lista[pos2]
        lista[pos2] = aux

        return lista
    
    def movimento(self):
        for i in range(len(self.pieces)): 
            if self.pieces[i] == 0: 
                pos = i
                break
                
        abaixo = [3, 3, 3, 3, 3, 3, 0, 0, 0];
        acima = [0,0,0,-3,-3,-3,-3,-3,-3];
        esquerda = [0,-1,-1,0,-1,-1,0,-1,-1];
        direita = [1,1,0,1,1,0,1,1,0];
        
        if(abaixo[pos] != 0):
            self.direcoes.append('abaixo')
            self.vizinhos.append(copy.deepcopy(self.pieces))
            self.tamanhoVizinhos += 1
            
            self.vizinhos[self.tamanhoVizinhos-1] = self.swap(self.vizinhos[self.tamanhoVizinhos-1], pos, pos+3)
            
        if (acima[pos] != 0):
            self.direcoes.append('acima')
            self.vizinhos.append(copy.deepcopy(self.pieces))
            self.tamanhoVizinhos += 1
            
            self.vizinhos[self.tamanhoVizinhos-1] = self.swap(self.vizinhos[self.tamanhoVizinhos-1], pos, pos-3)
        
        if (esquerda[pos] != 0):
            self.direcoes.append('esquerda')
            self.vizinhos.append(copy.deepcopy(self.pieces))
            self.tamanhoVizinhos += 1
            
            self.vizinhos[self.tamanhoVizinhos-1] = self.swap(self.vizinhos[self.tamanhoVizinhos-1], pos, pos-1)
        
        if (direita[pos] != 0):
            self.direcoes.append('direita')
            self.vizinhos.append(copy.deepcopy(self.pieces))
            self.tamanhoVizinhos += 1
            
            self.vizinhos[self.tamanhoVizinhos-1] = self.swap(self.vizinhos[self.tamanhoVizinhos-1], pos, pos+1)