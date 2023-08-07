# How To Learn Cryptography in Practice


This tutorial help you learn about cryptography in Pratice.

## Este projeto é para quem deseja aprender sobre cryptografia de modo prático!

## Get Start!!!!

Este projeto está baseado no livro: [Criptografia e Segurança de Redes: princípios e práticas do autor  William Stallings](https://www.amazon.com.br/gp/product/B0167CVE0E/ref=dbs_a_def_rwt_hsch_vapi_tkin_p1_i1). Disponível para Download em: [link](https://www.cs.vsb.cz/ochodkova/courses/kpb/cryptography-and-network-security_-principles-and-practice-7th-global-edition.pdf)


# Captítulo 3 - Técnicas de Subistituição

## 3.1 - Cífras de César.
 
 Como criar cifras de César:

 ```
# Texto em claro
echo "meet me after the toga party" > caesar-cipher-plaintext.txt
# Texto criptografado
rotix -f caesar-cipher-plaintext.txt -o caesar-ciphertext.txt -L -r 3
# criando todas as possibilidades
./caesar-cipher.sh 'meet me aftert the toga party'

 ```

