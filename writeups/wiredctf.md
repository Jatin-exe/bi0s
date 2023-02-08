# Wired CTF


**This was my first CTF  and here is how it went:-**



## OFFLINE HARDWARE:
###  Aint no Sunshine

This was the only offline challenge i was able to do.
1. I saw the circuit diagram and tried to create a circuit like it.
2. I ran into problems giving permissions to Arudino IDE to use ports but eventually i was able to get the flag.


## CRYPTOGRAPHY:
### Caeser Cipher
1. I just used an [online tool](https://www.boxentriq.com/code-breaking/caesar-cipher)  to decrypt this message and get the flag.
### Lifetimesetttlement


1. I first thought the message was binary but i was wrong.
2. Then i tried to identify the cipher
3. I tried online cipher identifiers but none of them worked and i was stuck on this for a while.
4. Later i tried to analyze the message using dcode.fr and was able to identify it as spoon cipher
-	*the dcoder.fr site wasnt loading for me and no other websites could identify the cipher*
 
### da_french_cipher
1. I used online cipher analyzer to identify the cipher and decode it and got the flag


## WIRELESS:
### Dots&Dashes
1. We got an audio file in the challenge, when i played it it had a rick roll at start and it ended with beep boop sounds, due to my movie watching experience i guessed it might be morse code.
2.  I searched online for morse code analyzers
3. I found one where we can submit audio files and translate the morse code.
4. The translation contained a bit of gibberish at start and the flag at the end.


### chan's fav
This was a really unique challenge, I wasnt able to solve it easily.
1. We were given an audio file which was just static noise.I was confused how to even proceed from here. 
2. Then i learnt that we can hide things in text,audios,videos and so on. So i searced for online audio analyzers to identify hidden messages in audio file.
3. Apparentlly there was photo of Rick Astley when we change the audio file to spectogram mode
4. The name was the flag

## HARDWARE:
### ~logic
1. This challenge was TRIVIAL it was just basic reversing of logic gates to get the optimal answer

## OSINT:
### find_thyself
1. we are given a picture of a socket with a brand name on it 
2. we have to guess the country this socket is in 
3. i tried searching for country and their sockets but couldnt get anything
4. then i searched for the brand and the brand was based in Italy
5. I tried Italy and it was correct

## REVERSING:
### xoring
1. We are given a python script which codes a message using XOR
2. We are also given the XOR coded flag and we have to decrypt it by understanding how the script works and decoding it 
3. After understandin how it encodes a message, I wrote a python script which decodes any given message, I ran it, I got the flag. 

>**How it works**
> Let msg to encode by  msg = "abc"
> key = "key"
> We encode each character one by one of the msg 
> We take one character each from both strings (a,k)
>  first we convert a to its ASCII number then we convert k to its ASCII no
>  We then XOR both of these no and get the ASCII character representation of the result no and  that is the encoded character

**Properties of XOR (^)**
1. a ^ 0 = a 
2. a ^ a = 0
3. if (a \^ b == c) then ; ( a ^ c \== b) and  ( b \^ c == a )



###  grep_it
1. Used `cat <file name>` to see the file
2. It was non human readable, tried `strings` and then `grep`
3. Used `grep -a 'wired'` command in linux to get the flag

### D0Z3N_IS_KEY

1. Tried to `grep` 'wired' and 'flag' didnt work
2.  Tried `cat` and `strings` on the file
3.  Piped strings and grep 'flag'
4. Got something which looked like encrypted text
5. Used online cipher to bruteforce and decode the text
6. Got yaa 

## MISC:
### sanity-check 1
1. Joined the Discord Server and got the flag
### sanity-check 2
1. Filled a form and got the flag
### IRC
1. Joined the bi0s-hardware IRC ( Internet Relay Chat) to get the flag

End of Challenges I did.


