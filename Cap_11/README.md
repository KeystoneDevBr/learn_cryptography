# Funções Hash

## Introdução

As principais funções hash são as famíias SHA-1, SHA-2 e SHA-3, sendo que as duas primeiras se diferem pelo comprimento das cifras, enquanto a terceira se difere pelo método de geração da cifra.

## Cálculo de Hash MD5, HA-1, SHA-2 e SHA-3

```sh
#1 - Listagem de funções Hash suportadas pelo OpenSSL
openssl list -digest-algorithms
openssl list -digest-commands
man dgst

#2 - Exemplo de Cálculo de hashs
openssl dgst -md5 ./BarackObama.pdf
md5sum ./BarackObama.pdf
openssl dgst -sha256 ./BarackObama.pdf
openssl dgst -sha3-256 ./BarackObama.pdf
sha384sum BarackObama.pdf

#3 Validação do Hash
echo "3d515dead7aa16560aba3e9df05cbc80  ./BarackObama.pdf" | md5sum -c

#4 Comparação de hashes SHA-1 e SHA-2
sha1sum shattered-1.pdf ; 
sha224sum shattered-1.pdf ; 
sha256sum shattered-1.pdf ;   
sha384sum shattered-1.pdf ;  
sha512sum shattered-1.pdf ;
openssl dgst -sha512-224 shattered-1.pdf ;
openssl dgst -sha512-256 shattered-1.pdf ;

#6 Comparação do Secure Hash Algorithm 3 - Nova geração de Hash
openssl dgst -sha3-224 shattered-1.pdf;
openssl dgst -sha3-256 shattered-1.pdf;
openssl dgst -sha3-384 shattered-1.pdf;
openssl dgst -sha3-512 shattered-1.pdf; 

```

## Colisões MD5

O algorítmo MD5 é sucetível a colisões. Para exemplificar isso, o programa md5colison


```sh
#1 - Gerando Colisões MD5, por meio da aplicação md5colizon
unzip fastcoll_v1.0.0.1_source.zip 
# Saída: 
Archive:  fastcoll_v1.0.0.1_source.zip
  inflating: md5.cpp                 
  inflating: block0.cpp              
  inflating: block1.cpp              
  inflating: main.cpp                
  inflating: main.hpp  

#1.1  Gerando as Colizões
g++ *.cpp -o md5colizion
# Gerando os arquivos msg1 e msg2
./md5colizion
# Comparados os arquivos gerados
cmp msg1 msg2

openssl dgst -md5 msg1 msg2                 
#MD5(msg1)= aad4869cecd7da12c2b024cd5f2b27dd
#MD5(msg2)= aad4869cecd7da12c2b024cd5f2b27dd

# 2 Comparando os arquivos pdf (Todos eles estão colidindo o valor do hash MD5)
openssl dgst -md5 *.pdf           
#MD5(BarackObama.pdf)= 3d515dead7aa16560aba3e9df05cbc80
#MD5(JohnMcCain.pdf)= 3d515dead7aa16560aba3e9df05cbc80
#MD5(ParisHilton.pdf)= 3d515dead7aa16560aba3e9df05cbc80

```

## Colisões SHA-1

A primeira descoberta relacionada a colisões do hash SHA-1 foi publicada pelo site: [https://shattered.io/](https://shattered.io/).

Veja o artigo sobre o tema: [The first collision for full SHA-1](https://shattered.it/static/shattered.pdf)

Comparação dos hash SHA-1 dos arquivos: 

```sh
#1 Verificando Arquivos com SHA1
openssl dgst -sha1 shattered-*
#SHA1(shattered-1.pdf)= 38762cf7f55934b34d179ae6a4c80cadccbb7f0a
#SHA1(shattered-2.pdf)= 38762cf7f55934b34d179ae6a4c80cadccbb7f0a
```