# Cifras Assimétricas

# Cap 9 - Criptografia de Chave Pública com RSA (Rivest-Shamir-Adleman)

Com a criptografia assimétrica é possível prover, de maneira revolucionária, tanto a confidencialidade quanto a autenticidade. Estes dois atributos podem ser providos de maneira individual ou juntos.

Outro assunto indispensável para se trabalhar com criptografia assimétrica é a criação de certificados digitais.

A seguir, serão abordadas, de maneira prática, a garantia da confidencialidade, autencidade e a criação de certificados digitais.

## Cap 9.1 - Provendo Autenticidade com RSA  - (Assinatura Digital)

Além da confidencialidade de uma mensagem, o mecanismo criptográfico de Cifras Assimétricas RSA, possibilita a assinatura digital, de forma prover a autenticidade de uma mensagem. Certificando assim que a mensagem realmente foi originada pelo remetente (quem envia).

Conforme o exemplo da imagem a seguir, o remetente utiliza sua Chave Privada para realizar a assinatura da mensagem. Após a assinatura, a mensagem é enviada ao destinatário. Em posse da mensagem, o destinatário poderá utilizar a chave pública do rementente para realizar a sua validação. 

Todo esse processo provê a autenticidade (Assinatura digital) da mensagem.

<img src="./garantia-da-autenticidade.jpg" width="60%">

## Passo a Passo para Simular o processo de assinatura digital.

## Passo 1 - 