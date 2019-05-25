#include "platformserver.h"
#include <stdlib.h>
#include <QRandomGenerator>

#define Positive true
#define Negative false

PlatformServer::PlatformServer(QObject *parent)
    : QTcpServer(parent)
{
    Books.resize(10);
    Movies.resize(10);
    Quotes.resize(10);
    Tags.resize(30);

    //Tags Population
    Tags[0] = Tag("relationships", "Extraverted", Positive);
    Tags[1] = Tag("beach-reading", "Extraverted", Positive);
    Tags[2] = Tag("south-africa", "Extraverted", Positive);
    Tags[3] = Tag("manga-collection", "Extraverted", Negative);
    Tags[4] = Tag("parallel-world", "Extraverted", Negative);
    Tags[5] = Tag("forgotten-realms", "Extraverted", Negative);
    Tags[6] = Tag("christian-classics", "Agreeable", Positive);
    Tags[7] = Tag("Relationships", "Agreeable", Positive);
    Tags[8] = Tag("family-drama", "Agreeable", Positive);
    Tags[9] = Tag("dark-and-dangerous", "Agreeable", Negative);
    Tags[10] = Tag("italian-renaissance", "Agreeable", Negative);
    Tags[11] = Tag("psychological-drama", "Agreeable", Negative);
    Tags[12] = Tag("philosophy-psychology", "Open", Positive);
    Tags[13] = Tag("university-readings", "Open", Positive);
    Tags[14] = Tag("philosophical-novel", "Open", Positive);
    Tags[15] = Tag("christian-classics", "Open", Negative);
    Tags[16] = Tag("girly-fiction", "Open", Negative);
    Tags[17] = Tag("light-fantasy", "Open", Negative);
    Tags[18] = Tag("dark-and-dangerous", "Neurotic", Positive);
    Tags[19] = Tag("mental-issues", "Neurotic", Positive);
    Tags[20] = Tag("pretty-writing", "Neurotic", Positive);
    Tags[21] = Tag("science-and-technology", "Neurotic", Negative);
    Tags[22] = Tag("politics-economics", "Neurotic", Negative);
    Tags[23] = Tag("professional-reading", "Neurotic", Negative);
    Tags[24] = Tag("professional-reading", "Conscientious", Positive);
    Tags[25] = Tag("theology-religion", "Conscientious", Positive);
    Tags[26] = Tag("brain-food", "Conscientious", Positive);
    Tags[27] = Tag("modern-fantasy", "Conscientious", Negative);
    Tags[28] = Tag("mental-issues", "Conscientious", Negative);
    Tags[29] = Tag("graphica", "Conscientious", Negative);


    //Books Population
    Books[0] = Book("Harry Potter and the Deathly Hallows", "Harry Potter is leaving Privet Drive for the last time. \
But as he climbs into the sidecar of Hagrid’s motorbike and they take to the skies, he knows Lord\
Voldemort and the Death Eaters will not be far behind. The protective charm that has kept him safe \
until now is broken. But the Dark Lord is breathing fear into everything he loves. And he knows he \
can’t keep hiding. To stop Voldemort, Harry knows he must find the remaining Horcruxes and destroy \
them. He will have to face his enemy in one final battle.", 27, 0, 14);

    Books[1] = Book("The Help", "Be prepared to meet three unforgettable women: Twenty-two-year-old Skeeter has just \
returned home after graduating from Ole Miss. She may have a degree, but it is 1962, Mississippi, \
and her mother will not be happy till Skeeter has a ring on her finger. Skeeter would normally \
find solace with her beloved maid Constantine, the woman who raised her, but Constantine has \
disappeared and no one will tell Skeeter where she has gone. Aibileen is a black maid, a wise, regal woman raising her seventeenth white child.\
Something has shifted inside her after the loss of her own son, who died while his bosses looked the other way.\
She is devoted to the little girl she looks after, though she knows both their hearts may be broken.\
Minny, Aibileen’s best friend, is short, fat, and perhaps the sassiest woman in Mississippi. She can cook like nobody’s\
business, but she can’t mind her tongue, so she’s lost yet another job. Minny finally finds a position working for someone\
too new to town to know her reputation. But her new boss has secrets of her own. Seemingly as different from one another\
as can be, these women will nonetheless come together for a clandestine project that will put them all at risk. And why?\
Because they are suffocating within the lines that define their town and their times. And sometimes lines are made to be\
crossed. In pitch-perfect voices, Kathryn Stockett creates three extraordinary women whose determination to start a\
movement of their own forever changes a town, and the way women — mothers, daughters, caregivers, friends — view one\
another. A deeply moving novel filled with poignancy, humor, and hope, The Help is a timeless and universal story about\
the lines we abide by, and the ones we don't.", 16, 2, 19);

    Books[2] = Book("1984", "Among the seminal texts of the 20th\
century, Nineteen Eighty-Four is a rare work that grows more haunting as its futuristic purgatory becomes more real.\
Published in 1949, the book offers political satirist George Orwell's nightmare vision of a totalitarian, bureaucratic\
world and one poor stiff's attempt to find individuality. The brilliance of the novel is Orwell's prescience of modern\
life--the ubiquity of television, the distortion of the language--and his ability to construct such a thorough version\
of hell. Required reading for students since it was published, it ranks among the most terrifying novels ever written. ",
13, 5, 28);

    Books[3] = Book("The Great Gatsby", "THE GREAT GATSBY, F. Scott Fitzgerald's third book, stands as the supreme achievement of his career. This exemplary novel of the Jazz Age has\
been acclaimed by generations of readers. The story is of the fabulously wealthy Jay Gatsby and his new love for the\
beautiful Daisy Buchanan, of lavish parties on Long Island at a time when The New York Times noted 'gin was the\
national drink and sex the national obsession,' it is an exquisitely crafted tale of America in the 1920s.\
                                                                                   \
                                                                                   The Great Gatsby is one of\
the great classics of twentieth-century literature.", 11, 29, 20);

    Books[4] = Book("The Book Thief ", "It is 1939. Nazi Germany. The country is holding its breath.\
Death has never been busier, and will be busier still.\
 \
By her brother's graveside, Liesel's life is changed when\
she picks up a single object, partially hidden in the snow. It is The Gravedigger's Handbook, left behind there by accident,\
and it is her first act of book thievery. So begins a love affair with books and words, as Liesel, with the help of her\
accordian-playing foster father, learns to read. Soon she is stealing books from Nazi book-burnings, the mayor's wife's\
library, wherever there are books to be found.\
 \
But these are dangerous times. When Liesel's foster family\
hides a Jew in their basement, Liesel's world is both opened up, and closed down.\
                                                              \
In superbly crafted writing that burns with intensity,\
award-winning author Markus Zusak has given us one of the most enduring stories of our time.",
1, 8, 17);

    Books[5] = Book("A Christmas Carol ", "H'If I had my way, every idiot who\
goes around with Merry Christmas on his lips, would be boiled with his own pudding, and buried with a stake of holly\
through his heart. Merry Christmas? Bah humbug!'\
                                                \
Introduction and Afterword by Joe\
Wheeler\
To bitter, miserly Ebenezer Scrooge,\
Christmas is just another day. But all\
that changes when the ghost of his long-dead business partner appears, warning Scrooge to change his ways before it's too\
late.\
     \
Part of the Focus on the Family\
Great Stories collection, this edition features an in-depth introduction and discussion questions by Joe Wheeler to\
provide greater understanding for today's reader. 'A Christmas Carol' captures the heart of the holidays like no other\
novel.", 6, 15, 7);

    Books[6] = Book("One Hundred Years of Solitude", "The brilliant, bestselling, landmark novel\
that tells the story of the Buendia family, and chronicles the irreconcilable conflict between the desire for solitude\
and the need for love—in rich, imaginative prose that has come to define an entire genre known as 'magical realism.'",
12, 23, 3);

    Books[7] = Book("Thoughts on Art and Life ", "A fascinating collection of writings from\
the great polymath of the Italian Renaissaince, Leonardo da Vinci. There are sections covering the great man's thoughts\
on life, art and science. Maurice Baring trawled the available manuscripts to distil da Vinci's writings on these\
subjects into a single, accessible tome, which will be of interest to students of da Vinci, the Renaissance and the\
history of both art and science. ", 25, 10, 4);

    Books[8] = Book("The Twelve Kingdoms: Sea of Shadow", "For high-schooler Yoko Nakajima, life has been fairly ordinary--that\
is until Keiki, a young man with golden hair, tells Yoko they must return to their kingdom. Once confronted by this\
mysterious being and whisked away to an unearthly realm, Yoko is left with only a magical sword; a gem; and a million\
questions about her destiny, the world she's trapped in, and the world she desperately wants to return to. "
,22, 18, 24);

    Books[9] = Book("The Deep Dark Web: The Hidden World ", "This Book covers the main aspects of the exciting and dangerous world of\
-The Deep Dark Web- . We are two cyber specialists Pierluigi (Italy) & Richard (US), with one passion we wanted to\
explain the inner working of the deep dark web. Cybercrime, hacktivism, intelligence, cyber warfare are all pieces\
of this complex puzzle. Governments, corporations and criminals all hide but we unveil it all.",
9, 26, 21);


    //Movies Population
    Movies[0] = Movie("Home Alone (1990)", "An eight-year-old troublemaker must protect his house\
from a pair of burglars when he is accidentally left home alone by his family during Christmas vacation. ",
0, 8, 17);
    Movies[1] = Movie("The Polar Express (2004)", "On Christmas Eve, a young boy embarks\
on a magical adventure to the North Pole on the Polar Express, while learning about friendship, bravery, and the\
spirit of Christmas.", 6, 15, 27);
    Movies[2] = Movie("The Holiday (2006)", "Two women troubled with guy-problems swap homes\
in each other's countries, where they each meet a local guy and fall in love. ", 11, 16, 23);
    Movies[3] = Movie("The Nutcracker and the Four Realms (2018)", " A young girl is transported\
into a magical world of gingerbread soldiers and an army of mice. ", 4, 5, 18);
    Movies[4] = Movie("Die Hard (1988)", "John McClane, officer of the NYPD,\
tries to save his wife Holly Gennaro and several others that were taken hostage by German terrorist\
Hans Gruber during a Christmas party at the Nakatomi Plaza in Los Angeles. ", 9, 19, 29);
    Movies[5] = Movie("Robin Hood (2018)", "A war-hardened Crusader and his Moorish\
commander mount an audacious revolt against the corrupt English crown in a thrilling action-adventure\
packed with gritty battlefield exploits, mind-blowing fight choreography, and a timeless romance.",
14, 24, 13);
    Movies[6] = Movie("Spider-Man: Far From Home (2019)", "After the events\
of Avengers: Endgame Peter Parker and his friends go on summer vacation to Europe and there Peter\
finds himself trying to save his friends against a villain known as Mysterio. ", 21, 1, 7);
    Movies[7] = Movie("Elizabeth (1998)", "The early years of the reign of Elizabeth\
I of England and her difficult task of learning what is necessary to be a monarch. ", 22, 28, 12);
    Movies[8] = Movie("A Beautiful Mind (2001)", "After John Nash, a brilliant but\
asocial mathematician, accepts secret work in cryptography, his life takes a turn for the nightmarish. "
, 3, 20, 26);
    Movies[9] = Movie("Leonardo da Vinci - Il genio a Milano (2016)", "'Leonardo da Vinci.\
The Genius in Milan' is a docufilm by Luca Lucini and Nico Malaspina. Through scenes of fiction and interviews\
with the greatest Leonardo da Vinci world experts, the docufilm explores the years that the artist spent in Milan\
at the court of Ludovico il Moro and reveals some of Leonardo's greatest works.", 25, 2, 10);


    //Quotes Population
    Quotes[0] = Quote("Indifference and neglect often do much more damage than outright dislike.\
― J.K. Rowling, Harry Potter and the Order of the Phoenix  ", 27, 0, 14);

    Quotes[1] = Quote("Sometimes fate is like a small sandstorm that keeps changing directions. You change direction\
but the sandstorm chases you. You turn again, but the storm adjusts. Over and over you play this out, like some ominous\
dance with death just before dawn. Why? Because this storm isn't something that blew in from far away, something that has\
nothing to do with you. This storm is you. Something inside of you. So all you can do is give in to it, step right inside\
the storm, closing your eyes and plugging up your ears so the sand doesn't get in, and walk through it, step by step.\
There's no sun there, no moon, no direction, no sense of time. Just fine white sand swirling up into the sky like pulverized\
bones. That's the kind of sandstorm you need to imagine.\
\
An you really will have to make it through that violent, metaphysical, symbolic storm. No matter\
how metaphysical or symbolic it might be, make no mistake about it: it will cut through flesh like a thousand razor blades.\
People will bleed there, and you will bleed too. Hot, red blood. You'll catch that blood in your hands, your own blood and\
the blood of others.\
\
And once the storm is over you won't remember how you made it through, how you managed to\
survive. You won't even be sure, in fact, whether the storm is really over. But one thing is certain. When you come out\
of the storm you won't be the same person who walked in. That's what this storm's all about.\
― Haruki Murakami, Kafka on the Shore ", 12, 18, 9);

    Quotes[2] = Quote("Up to a certain point it is good for us to know that there are people in the world who\
will give us love and unquestioned loyalty to the limit of their ability. I doubt, however, if it is good for us to\
feel assured of this without the accompanying obligation of having to justify this devotion by our behavior.\
― Eleanor Roosevelt, This is My Story ", 7, 26, 23);

    Quotes[3] = Quote("Darkness cannot drive out darkness: only light can do that. Hate cannot drive out hate:\
only love can do that.\
― Martin Luther King Jr., A Testament of Hope: The Essential Writings and Speeches "
, 24, 22, 2);

    Quotes[4] = Quote("To be yourself in a world that is constantly trying to make you something else \
is the greatest accomplishment.\
― Ralph Waldo Emerson ",
25, 4, 13);

    Quotes[5] = Quote("If you judge people, you have no time to love them.\
― Mother Teresa", 6, 15, 1);

    Quotes[6] = Quote("He's like a drug for you, Bella.\
― Stephenie Meyer, Eclipse ", 16, 11, 29);

    Quotes[7] = Quote("Our deepest fear is not that we are inadequate. Our deepest fear is that we are powerful\
 beyond measure. It is our light, not our darkness that most frightens us. We ask ourselves, 'Who am I to be brilliant,\
gorgeous, talented, fabulous?' Actually, who are you not to be? You are a child of God. Your playing small does not serve\
the world. There is nothing enlightened about shrinking so that other people won't feel insecure around you. We are all\
meant to shine, as children do. We were born to make manifest the glory of God that is within us. It's not just in some\
of us; it's in everyone. And as we let our own light shine, we unconsciously give other people permission to do the same.\
As we are liberated from our own fear, our presence automatically liberates others.\
                       ― Marianne Williamson, A Return to Love: Reflections on the Principles of A Course in Miracles "
,28, 19, 20);

    Quotes[8] = Quote("In her (Nature’s) inventions nothing is lacking, and nothing is superfluous.\
– Leonardo da Vinci", 10, 21, 17);

    Quotes[9] = Quote("Ayame: Yuki, let's deepen the bond between us brothers!\
Yuki: Before you can do that I'll drown you in the deepest part of that lake.\
Ayame: As long as we spend time together.\
Yuki: On second thought, go drown yourself.\
― Natsuki Takaya", 8, 5, 3);

}

int PlatformServer::saveInfo(PlatformClient client)
{
    int id = Clients.size();
    client.setId(id);
    Clients.push_back(client);
    return id;
}

void PlatformServer::generateBookRecommendation(int id)
{
    QMap<QString, int> Scores;
    Scores["Open"] = Clients[id].getOpennessScore();                           //open
    Scores["Conscientious"] = Clients[id].getConscientiousnessSScore();        //Conscientious
    Scores["Extraverted"] = Clients[id].getExtraversionScore();                 //Extraverted
    Scores["Agreeable"] = Clients[id].getAgreeablenessScore();                 //Agreeable
    Scores["Neurotic"] = Clients[id].getNeuroticismScore();                    //Neurotic

    int i = 0, SecondClosestBookId = -1, foundId = -1;
    bool found = false;
    QVector<int>matchCounter(10,0);
    //loop on 10 books
    while(i<10)
    {
        int tag1Id = Books[i].getTag1Id();
        int tag2Id = Books[i].getTag2Id();
        int tag3Id = Books[i].getTag3Id();

        /*  check if book[i]'s 1st tag and client's corresponding trait match
         *  ex.: tag1Id of Book[0] is 27, Tags[27] = Tag("modern-fantasy", "Conscientious", Negative);
         *  if client score for Conscientous trait is 0 then client has a negative correlation to Conscientious
         *  trait, and hence book[i] is a possible match
         * */
        if(Tags[tag1Id].getCorrelation() == Positive)
        {
            if(Scores[Tags[tag1Id].getTrait()] >=3)
                matchCounter[i]++;
         }
        else {
            if(Scores[Tags[tag1Id].getTrait()] <=2)
                matchCounter[i]++;
        }

        /*  repeat for book[i]'s 2nd tag: tag2Id
         * */
        if(Tags[tag2Id].getCorrelation() == Positive)
        {
            if(Scores[Tags[tag2Id].getTrait()] >=3)
                matchCounter[i]++;
         }
        else {
            if(Scores[Tags[tag2Id].getTrait()] <=2)
                matchCounter[i]++;
        }

        /*  repeat for book[i]'s 2nd tag: tag2Id
         * */
        if(Tags[tag3Id].getCorrelation() == Positive)
        {
            if(Scores[Tags[tag3Id].getTrait()] >=3)
                matchCounter[i]++;
         }
        else {
            if(Scores[Tags[tag3Id].getTrait()] <=2)
                matchCounter[i]++;
        }

        /*  If the three tags of book[i] match the client's analysis results
         * (5 Characteristics' scores for the OCEAN model), then book[i] is a match
         * */

        if(matchCounter[i] == 3)
        {
            found = true;
            break;
        }
        /*  In case there is no match between three tags of all books in database(10 books)
         *  Prepare a book with only 2 tags matching
         * */
        else if(matchCounter[i] == 2)
        {
            SecondClosestBookId = i;
        }
         i++;
    }

    //In case a book is found with 3 tags matching the users' analysis results
    if(found)
    {
        foundId = i;
    }
    //In case no 3-tag match book is found, use a 2-tag match book
    else if(SecondClosestBookId != -1)
    {
        foundId = SecondClosestBookId;
    }
    //In case neither 3-tag match nor 2-tag match is found, randomly generate a book from the database
    else {
        foundId = QRandomGenerator::global()->bounded(10);
    }


    Book generatedBook = Books[foundId];
    generatedBook.setTag1Name(Tags[generatedBook.getTag1Id()].getName());
    generatedBook.setTag2Name(Tags[generatedBook.getTag2Id()].getName());
    generatedBook.setTag3Name(Tags[generatedBook.getTag3Id()].getName());

    //save the found book in clients' database
    Clients[id].setBookRecommendation(generatedBook);
}

void PlatformServer::generateMovieRecommendation(int id)
{
    QMap<QString, int> Scores;
    Scores["Open"] = Clients[id].getOpennessScore();                           //open
    Scores["Conscientious"] = Clients[id].getConscientiousnessSScore();        //Conscientious
    Scores["Extraverted"] = Clients[id].getExtraversionScore();                 //Extraverted
    Scores["Agreeable"] = Clients[id].getAgreeablenessScore();                 //Agreeable
    Scores["Neurotic"] = Clients[id].getNeuroticismScore();                    //Neurotic

    int i = 0, SecondClosestMovieId = -1, foundId = -1;
    bool found = false;
    QVector<int>matchCounter(10,0);
    //loop on 10 movies
    while(i<10)
    {
        int tag1Id = Movies[i].getTag1Id();
        int tag2Id = Movies[i].getTag2Id();
        int tag3Id = Movies[i].getTag3Id();

        /*  check if movie[i]'s 1st tag and client's corresponding trait match
         *  ex.: tag1Id of Book[0] is 27, Tags[27] = Tag("modern-fantasy", "Conscientious", Negative);
         *  if client score for Conscientous trait is 0 then client has a negative correlation to Conscientious
         *  trait, and hence book[i] is a possible match
         * */
        if(Tags[tag1Id].getCorrelation() == Positive)
        {
            if(Scores[Tags[tag1Id].getTrait()] >=3)
                matchCounter[i]++;
         }
        else {
            if(Scores[Tags[tag1Id].getTrait()] <=2)
                matchCounter[i]++;
        }

        /*  repeat for movie[i]'s 2nd tag: tag2Id
         * */
        if(Tags[tag2Id].getCorrelation() == Positive)
        {
            if(Scores[Tags[tag2Id].getTrait()] >=3)
                matchCounter[i]++;
         }
        else {
            if(Scores[Tags[tag2Id].getTrait()] <=2)
                matchCounter[i]++;
        }

        /*  repeat for movie[i]'s 2nd tag: tag2Id
         * */
        if(Tags[tag3Id].getCorrelation() == Positive)
        {
            if(Scores[Tags[tag3Id].getTrait()] >=3)
                matchCounter[i]++;
         }
        else {
            if(Scores[Tags[tag3Id].getTrait()] <=2)
                matchCounter[i]++;
        }

        /*  If the three tags of movie[i] match the client's analysis results
         * (5 Characteristics' scores for the OCEAN model), then movie[i] is a match
         * */

        if(matchCounter[i] == 3)
        {
            found = true;
            break;
        }
        /*  In case there is no match between three tags of all movies in database(10 movies)
         *  Prepare a movie with only 2 tags matching
         * */
        else if(matchCounter[i] == 2)
        {
            SecondClosestMovieId = i;
        }
         i++;
    }

    //In case a book is found with 3 tags matching the users' analysis results
    if(found)
    {
        foundId = i;
    }
    //In case no 3-tag match book is found, use a 2-tag match book
    else if(SecondClosestMovieId != -1)
    {
        foundId = SecondClosestMovieId;
    }
    //In case neither 3-tag match nor 2-tag match is found, randomly generate a book from the database
    else {
        foundId = QRandomGenerator::global()->bounded(10);
    }


    Movie generatedMovie = Movies[foundId];
    generatedMovie.setTag1Name(Tags[generatedMovie.getTag1Id()].getName());
    generatedMovie.setTag2Name(Tags[generatedMovie.getTag2Id()].getName());
    generatedMovie.setTag3Name(Tags[generatedMovie.getTag3Id()].getName());

    //save the found movie in clients' database
    Clients[id].setMovieRecommendation(generatedMovie);
}

void PlatformServer::generateQuoteRecommendation(int id)
{
    QMap<QString, int> Scores;
    Scores["Open"] = Clients[id].getOpennessScore();                           //open
    Scores["Conscientious"] = Clients[id].getConscientiousnessSScore();        //Conscientious
    Scores["Extraverted"] = Clients[id].getExtraversionScore();                 //Extraverted
    Scores["Agreeable"] = Clients[id].getAgreeablenessScore();                 //Agreeable
    Scores["Neurotic"] = Clients[id].getNeuroticismScore();                    //Neurotic

    int i = 0, SecondClosestQuoteId = -1, foundId = -1;
    bool found = false;
    QVector<int>matchCounter(10,0);

    //loop on 10 quotes
    while(i<10)
    {
        int tag1Id = Quotes[i].getTag1Id();
        int tag2Id = Quotes[i].getTag2Id();
        int tag3Id = Quotes[i].getTag3Id();

        /*  check if quote[i]'s 1st tag and client's corresponding trait match
         *  ex.: tag1Id of Quotes[0] is 27, Tags[27] = Tag("modern-fantasy", "Conscientious", Negative);
         *  if client score for Conscientous trait is 0 then client has a negative correlation to Conscientious
         *  trait, and hence Quotes[i] is a possible match
         * */
        if(Tags[tag1Id].getCorrelation() == Positive)
        {
            if(Scores[Tags[tag1Id].getTrait()] >=3)
                matchCounter[i]++;
         }
        else {
            if(Scores[Tags[tag1Id].getTrait()] <=2)
                matchCounter[i]++;
        }

        /*  repeat for Quotes[i]'s 2nd tag: tag2Id
         * */
        if(Tags[tag2Id].getCorrelation() == Positive)
        {
            if(Scores[Tags[tag2Id].getTrait()] >=3)
                matchCounter[i]++;
         }
        else {
            if(Scores[Tags[tag2Id].getTrait()] <=2)
                matchCounter[i]++;
        }

        /*  repeat for Quotes[i]'s 2nd tag: tag2Id
         * */
        if(Tags[tag3Id].getCorrelation() == Positive)
        {
            if(Scores[Tags[tag3Id].getTrait()] >=3)
                matchCounter[i]++;
         }
        else {
            if(Scores[Tags[tag3Id].getTrait()] <=2)
                matchCounter[i]++;
        }

        /*  If the three tags of Quotes[i] match the client's analysis results
         * (5 Characteristics' scores for the OCEAN model), then Quotes[i] is a match
         * */

        if(matchCounter[i] == 3)
        {
            found = true;
            break;
        }
        /*  In case there is no match between three tags of all quotes in database(10 quotes)
         *  Prepare a quote with only 2 tags matching
         * */
        else if(matchCounter[i] == 2)
        {
            SecondClosestQuoteId = i;
        }
         i++;
    }

    //In case a quote is found with 3 tags matching the users' analysis results
    if(found)
    {
        foundId = i;
    }
    //In case no 3-tag match quote is found, use a 2-tag match quote
    else if(SecondClosestQuoteId != -1)
    {
        foundId = SecondClosestQuoteId;
    }
    //In case neither 3-tag match nor 2-tag match is found, randomly generate a Quote from the database
    else {
        foundId = QRandomGenerator::global()->bounded(10);
    }


    Quote generatedQuote = Quotes[foundId];
    generatedQuote.setTag1Name(Tags[generatedQuote.getTag1Id()].getName());
    generatedQuote.setTag2Name(Tags[generatedQuote.getTag2Id()].getName());
    generatedQuote.setTag3Name(Tags[generatedQuote.getTag3Id()].getName());

    //save the found quote in clients' database
    Clients[id].setQuoteRecommendation(generatedQuote);
}

void PlatformServer::generateRecommendations(int id)
{
    this->generateBookRecommendation(id);
    this->generateMovieRecommendation(id);
    this->generateQuoteRecommendation(id);

    emit passRecommendationstoIOThread(Clients[id]);
}

void PlatformServer::handleInfo(PlatformClient client)
{
    int id = saveInfo(client);

    emit passInfotoGUI(Clients[id]);

    this->generateRecommendations(id);
}

void PlatformServer::handleFeedback(PlatformClient client)
{
    Clients[client.getId()].setFeedback(client.getFeedback());

    emit passFbtoGUI(Clients[client.getId()]);
}

void PlatformServer::incomingConnection(qintptr socketDescriptor)
{
    IOThread *thread = new IOThread(socketDescriptor, this);

    connect(thread, SIGNAL(finished()),
            thread, SLOT(deleteLater()));

    connect(thread, &IOThread::passInfoToServer,
            this, &PlatformServer::handleInfo);

    connect(this, &PlatformServer::passRecommendationstoIOThread,
            thread, &IOThread::handleRecommendations);

    connect(thread, &IOThread::passFbToServer,
            this, &PlatformServer::handleFeedback);

    thread->start();
}
