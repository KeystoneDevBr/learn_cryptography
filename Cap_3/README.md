# Cifas Simétricas
# Capítulo 3 - Técnicas Clássicas de Criptografia

## 3.1 - Cifras de César (Caesar Cipher)


Criar um arquivo com o texto em claro
```sh
echo "meet me after the toga party" > caesar-cipher-plaintext.txt
```
Criptografar o texto rotacionando-o 3 passos para a esquerda
```sh
rotix -f caesar-cipher-plaintext.txt -o caesar-ciphertext.txt -L -r 3

```
Criando todas as possiblidades com o executável caesar-chiper.sh
```sh
# sudo apt  install rotix -y
./caesar-cipher.sh 'meet me aftert the toga party'
```
Saída:
```sh
Key: 0 -- meet me aftert the toga party
Key: 1 -- ldds ld zesdqs sgd snfz ozqsx
Key: 2 -- kccr kc ydrcpr rfc rmey nyprw
Key: 3 -- jbbq jb xcqboq qeb qldx mxoqv
Key: 4 -- iaap ia wbpanp pda pkcw lwnpu
Key: 5 -- hzzo hz vaozmo ocz ojbv kvmot
Key: 6 -- gyyn gy uznyln nby niau julns
Key: 7 -- fxxm fx tymxkm max mhzt itkmr
Key: 8 -- ewwl ew sxlwjl lzw lgys hsjlq
Key: 9 -- dvvk dv rwkvik kyv kfxr grikp
Key: 10 -- cuuj cu qvjuhj jxu jewq fqhjo
Key: 11 -- btti bt puitgi iwt idvp epgin
Key: 12 -- assh as othsfh hvs hcuo dofhm
Key: 13 -- zrrg zr nsgreg gur gbtn cnegl
Key: 14 -- yqqf yq mrfqdf ftq fasm bmdfk
Key: 15 -- xppe xp lqepce esp ezrl alcej
Key: 16 -- wood wo kpdobd dro dyqk zkbdi
Key: 17 -- vnnc vn jocnac cqn cxpj yjach
Key: 18 -- ummb um inbmzb bpm bwoi xizbg
Key: 19 -- tlla tl hmalya aol avnh whyaf
Key: 20 -- skkz sk glzkxz znk zumg vgxze
Key: 21 -- rjjy rj fkyjwy ymj ytlf ufwyd
Key: 22 -- qiix qi ejxivx xli xske tevxc
Key: 23 -- phhw ph diwhuw wkh wrjd sduwb
Key: 24 -- oggv og chvgtv vjg vqic rctva
Key: 25 -- nffu nf bgufsu uif uphb qbsuz
```


## 3.2 Cifras Monoalfabéticas (Monoalphabetic Cipher)

Criando uma cifra monoalfabética apenas com comandos linux:

Permutando o alfabeto (abcdefghijkl.....) para DKVQFIBJWPESCXHTMYAUOLRGZN com o comando tr (translate or delete characters)
```sh
echo "abcdefghijklmnopqrstuvwxyz" | tr '[a-z]' '[DKVQFIBJWPESCXHTMYAUOLRGZN]'
# Desfaz a permutação
echo "DKVQFIBJWPESCXHTMYAUOLRGZN" | tr '[DKVQFIBJWPESCXHTMYAUOLRGZN]' '[a-z]'
```

Exemplo de cifragem de uma mensagem:

```sh
echo "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG" | tr '[DKVQFIBJWPESCXHTMYAUOLRGZN]' '[A-Z]'
# Desfaz a permutação
echo "POK DTFMB GWUIZ EUN HTQJL UCKW POK VSYR AUX" | tr '[A-Z]' '[DKVQFIBJWPESCXHTMYAUOLRGZN]'
```


texto
```sh

```
texto
```sh

```

texto
```sh

```
