asm = open("output_files/instructions.txt", "r").readlines()
asm = [l.strip().split(" ") for l in asm]
asm = [[int(a, 16) for a in l] for l in asm]

ip = 0 

# Memory of size 1024
mem = [0] * 1024    

NOP = 0   #skips
ADD = 1   #adds
MUL = 2   #multiplies
SUB = 3   #subtracts
DIV = 4   #divides
COP = 5   #copies
AFC = 6   #affects
JMP = 7   #jumps
JMF = 8   #jumps if
INF = 9   #inferior to
SUP = 10  #superior to
EQU = 11  #equal to
PRI = 12  #print
RET = 13  #return
NEQ = 14  #different
LEQ = 15  #less or equal to
GEQ = 16  #greater or equal to
AND = 17  #and
ORR = 18  #or
NOT = 19  #not
ERR = 255 #problem couldn't recognize instruction



while (ip < len(asm)) :
    #print(asm[ip][0])
    
    if asm[ip][0] == NOP:
        pass
    
    elif asm[ip][0] == ADD:
        mem[asm[ip][1]] = mem[asm[ip][2]] + mem[asm[ip][3]]
        
    elif asm[ip][0] == MUL: 
        mem[asm[ip][1]] = mem[asm[ip][2]] * mem[asm[ip][3]]
    
    elif asm[ip][0] == SUB: 
        mem[asm[ip][1]] = mem[asm[ip][2]] - mem[asm[ip][3]]
    
    elif asm[ip][0] == DIV: 
        mem[asm[ip][1]] = mem[asm[ip][2]] / mem[asm[ip][3]]
    
    elif asm[ip][0] == COP: 
        mem[asm[ip][1]] = mem[asm[ip][2]]
    
    elif asm[ip][0] == AFC: 
        mem[asm[ip][1]] = asm[ip][2]
    
    elif asm[ip][0] == JMP: 
        ip = asm[ip][1] - 1  #we decrease so that after ip+1, we get to the right instruction
        
    elif asm[ip][0] == JMF:  #works so that if 1 true, else is false and skips, not only 0 is false
        if mem[asm[ip][1]] == 1 : #true, we continue normally
            pass
        else : #false, we jump to else
            ip = asm[ip][2] - 1      
        
    elif asm[ip][0] == INF: 
        if mem[asm[ip][2]] < mem[asm[ip][3]] : #if it's true
            mem[asm[ip][1]] = 1 
        else:
            mem[asm[ip][1]] = 0
            
    
    elif asm[ip][0] == SUP: 
        if mem[asm[ip][2]] > mem[asm[ip][3]] : #if it's true
            mem[asm[ip][1]] = 1 
        else:
            mem[asm[ip][1]] = 0
        
    elif asm[ip][0] == EQU: 
        if mem[asm[ip][2]] == mem[asm[ip][3]] : #if it's true
            mem[asm[ip][1]] = 1 
        else:
            mem[asm[ip][1]] = 0
           
    elif asm[ip][0] == PRI: 
        print(mem[asm[ip][1]])

    elif asm[ip][0] == RET: 
        pass
        #TODO #a faire ---------------------------------------------------------------------
        
    elif asm[ip][0] == NEQ: 
        if mem[asm[ip][2]] != mem[asm[ip][3]] : #if it's true
            mem[asm[ip][1]] = 1 
        else:
            mem[asm[ip][1]] = 0
    
    elif asm[ip][0] == LEQ: 
        if mem[asm[ip][2]] <= mem[asm[ip][3]] : #if it's true
            mem[asm[ip][1]] = 1 
        else:
            mem[asm[ip][1]] = 0
    
    elif asm[ip][0] == GEQ: 
        if mem[asm[ip][2]] >= mem[asm[ip][3]] : #if it's true
            mem[asm[ip][1]] = 1 
        else:
            mem[asm[ip][1]] = 0
            
    elif asm[ip][0] == AND: 
        if ((mem[asm[ip][2]]==1) and (mem[asm[ip][3]]==1)) : #if both are true, true
            mem[asm[ip][1]] = 1 
        else:
            mem[asm[ip][1]] = 0
            
    elif asm[ip][0] == ORR: 
        if mem[asm[ip][2]] or mem[asm[ip][3]] : #if one of the two is true, true
            mem[asm[ip][1]] = 1 
        else:
            mem[asm[ip][1]] = 0
            
    elif asm[ip][0] == NOT: 
        if mem[asm[ip][2]] != 1 : #if it's not true, true
            mem[asm[ip][1]] = 1 
        else:
            mem[asm[ip][1]] = 0
    
    else : 
        print("error couldn't recognize instruction " + str(asm[ip][0]))
    
    ip+=1
