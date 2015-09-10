#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_24_841_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 23;
static uint_fast32_t endhere = 0;
char str[34] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[24][11] = {{0LLU,0LLU,16140901064495857664LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,2305843009213693951LLU,0LLU,0LLU,18446744071562067968LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2147483647LLU,0LLU,18374686479671623680LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{0LLU,18446744073709027328LLU,4611686018427387903LLU,18446743901238706174LLU,18446145800804136959LLU,6899233124090118143LLU,18446744073709551455LLU,72057594033733631LLU,18446744065119617024LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,524287LLU,16140901064495857664LLU,18446744073709550591LLU,144115188071661439LLU,18446726481523507199LLU,18410717475713843199LLU,18446744073642180607LLU,8589934591LLU,18446744073709550592LLU,70368744177663LLU},{0LLU,18446744073709551615LLU,3746994889972252287LLU,18410963766314270719LLU,18379190044939223039LLU,18302628872748761088LLU,36027706097209343LLU,72057594033602560LLU,18446744073709551584LLU,18446739675663041535LLU,70368744177663LLU},{18446744073709551615LLU,1148453088814694400LLU,18392140118727854047LLU,18446743340711651258LLU,18445993514123326719LLU,6318162063696855039LLU,18446744073709550933LLU,18446744073709551615LLU,18446744065119617055LLU,4398046511103LLU,70368744176640LLU},{18446744069414584320LLU,18446744073709518799LLU,13546827679063605247LLU,17291845595652038655LLU,16127337454192558071LLU,18300517818743914368LLU,34339886488080335LLU,16203916205784825848LLU,17906312115991206783LLU,18446744073642443775LLU,70368743916543LLU},{4294967295LLU,18446708889874325500LLU,8646911284551351935LLU,18340883093985951719LLU,17960355313953489919LLU,14987979138965405823LLU,18446710057568255999LLU,2305280059254374407LLU,18446739692771573696LLU,18446739675730149375LLU,70368677330943LLU},{18374967954648268800LLU,18446744073709551555LLU,18446744073709551615LLU,16847664884235081727LLU,18405314440709816279LLU,4440091835375805944LLU,17329850942524714956LLU,4527067259522245055LLU,18446744066835911484LLU,9187334186044490751LLU,70367737529335LLU},{18446742974197989375LLU,35184372039679LLU,13546827679063603200LLU,18445050825802676767LLU,14402508309795962877LLU,18445029381030805127LLU,1150704837491417087LLU,16285007439298822088LLU,17888302117962121215LLU,17867890783030607871LLU,70352637804415LLU},{18374967954648268800LLU,18446744073709551555LLU,16140901064495859711LLU,18158513694336614399LLU,2305843008804880255LLU,18446744073642438649LLU,17330414316074041340LLU,18444492273534887935LLU,18014398509481983LLU,9187334186044489728LLU,70367737529335LLU},{18446744073709551360LLU,1152921504539639807LLU,18446741874686298079LLU,18158513694319837695LLU,11528093544207744963LLU,18158522493575888893LLU,18222127038266867708LLU,18444227875700735999LLU,7740555413918719LLU,5714214706109989887LLU,70248417753335LLU},{18374687579166474495LLU,17298326031826419456LLU,16140903263519112831LLU,18442240474082181119LLU,8502796035937488767LLU,18446744073709545963LLU,10637390032224124927LLU,4611686015922070591LLU,18446611874616180734LLU,18446743799901207552LLU,69405728294911LLU},{281474976710400LLU,18446709026709233663LLU,8646909085595205631LLU,18419704883742638055LLU,13509743350948822991LLU,18160765076458407933LLU,18223788676020666367LLU,18446532555160028159LLU,576456624837736417LLU,16131326534421038079LLU,70248355069439LLU},{72056494543077120LLU,1152886457606479871LLU,3746992699472082944LLU,18427603775278447207LLU,10088063165309911039LLU,18192829030258941597LLU,8998305820579987455LLU,16429131440647446472LLU,594611765132656611LLU,18446739949471384575LLU,70233393758207LLU},{17365880098464464880LLU,1152813889899986175LLU,18446743944655267824LLU,9204231738438451199LLU,10016005639991459776LLU,18446744073709526685LLU,9148349571091398655LLU,18158512602341154798LLU,14878907174263714299LLU,18445687717699253247LLU,67050873519167LLU},{1148681852462100495LLU,18378031185788674047LLU,3738548576876165135LLU,18446674804462221927LLU,18446744073709551615LLU,18192829030258966527LLU,15693582350921171967LLU,16717361816799180633LLU,4162422217243623399LLU,18446740719557349363LLU,57058589999103LLU},{17298062221247451120LLU,17365772419583179776LLU,16149908134696314480LLU,18446744073709551615LLU,73183433406762879LLU,18446744073709529769LLU,13165486260292157439LLU,9223371484593630446LLU,14878942159993569278LLU,18446743029815242767LLU,66244767109119LLU},{8991374518551824252LLU,8968865438697258666LLU,18306832288420328316LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,13165485160780595199LLU,9223371484593630446LLU,17257476760614731775LLU,18446743725744782223LLU,51401899109379LLU},{15221390295573544403LLU,15266844741576160597LLU,16283815207234416307LLU,70368744177663LLU,73183433406762816LLU,18446744073709529769LLU,18446744073709551615LLU,18446744073709551615LLU,11310146545464115198LLU,18446742259729278075LLU,32435054043135LLU},{18293586493381271549LLU,18302628593575919615LLU,18320643266962784253LLU,18446744073709551615LLU,63LLU,18446744071562067968LLU,18446742974198054911LLU,9223372036854775295LLU,17257476760614731775LLU,18446743725744782223LLU,51401899109379LLU},{4455136716383310653LLU,18248559003325956095LLU,4532871358450235517LLU,18446674804462221927LLU,72057594037927935LLU,18229440716617023488LLU,18446742978492827647LLU,17293822569102704639LLU,7732343731679920111LLU,18446741489643314103LLU,43903122014207LLU},{4455136716383310653LLU,4409560297866006527LLU,4478379554661235165LLU,18446708156331109034LLU,18445993514123326719LLU,18446744071562100735LLU,18446744073709551615LLU,17293822569102704639LLU,18437736865865400303LLU,288230376151711743LLU,43903122013184LLU}};

static uint_fast64_t D[24][11] = {{18446744073709551615LLU,18446744073709551615LLU,16140901064495857663LLU,106286122620245LLU,18304505353838893440LLU,12165158514146202966LLU,8034419536205776554LLU,18374688131444431283LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{7378697629483820646LLU,7377825056896850602LLU,16414719920175633254LLU,18446744073709551615LLU,18446744073709551615LLU,6281585559563403263LLU,10412324537503775061LLU,18446742421936744012LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{11068046444225730969LLU,11068919016812701013LLU,4337867162747612313LLU,18446637787586931370LLU,142238719870658175LLU,18446744073709497001LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,12934196012542425429LLU,69729633440751400LLU,18083046757193875455LLU,18410716370343687930LLU,18403577048451383295LLU,8589934591LLU,18446744073709550592LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,2305843009213693951LLU,5512654174818899966LLU,18378292635564388823LLU,981327288856401238LLU,8034420641575931663LLU,43168676959410611LLU,18446744065119617024LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,1148453088815218687LLU,18392140118727854047LLU,12934337289017483673LLU,18446515643694578728LLU,17575163850784899071LLU,18446744072145992944LLU,18403577048451383295LLU,17841990679610261503LLU,4398046510284LLU,70368744176640LLU},{18446744073709551615LLU,18446744073709551615LLU,17582052945254415999LLU,18410821929312157559LLU,2251748004585471LLU,18229440718764474368LLU,4294903807LLU,18446744073709420544LLU,604753402689224703LLU,18446739675663041331LLU,70368744177663LLU},{18446744073709551615LLU,18446708889337978876LLU,18428696681328410623LLU,13726970839339499489LLU,18014186572173262894LLU,14116532515495608319LLU,18446711087202696447LLU,18409795937865170943LLU,17870278931878215647LLU,11068049083053637358LLU,70368677330329LLU},{18446744073709551615LLU,1148453089351532495LLU,18410187511042148319LLU,16429131373001703839LLU,16140831794728140785LLU,18444499420249849855LLU,18445055222902423488LLU,18430919781591810047LLU,17878019482785274751LLU,7378699388702424541LLU,70368743916134LLU},{18446742978492891135LLU,499711LLU,18446744073709549568LLU,13835057230648441345LLU,16285012122960658428LLU,18446717718716088063LLU,18446183322561281279LLU,18410702055707508687LLU,18428729683790004223LLU,17434313765846777855LLU,70352579067677LLU},{18374967954648334335LLU,18446744073709551600LLU,18428696681328410623LLU,17892783723076777983LLU,18409659745525825551LLU,254418194442216959LLU,18446743658169466876LLU,4607252375193903551LLU,17870283316895037340LLU,2242216212639514350LLU,70367729679859LLU},{18446742978492891135LLU,18446744073709527039LLU,2305843009213693951LLU,2211816141859323392LLU,18419718138548449788LLU,14987970764315614807LLU,8070449861972696127LLU,13924551673037381571LLU,18446744071993257155LLU,17434313765846777855LLU,70352579067677LLU},{18446462603011096575LLU,17298326031826419516LLU,18446744073709551231LLU,11449824877503053823LLU,17699146467383395327LLU,14987979558261618791LLU,10376181167911836735LLU,2107121671892106247LLU,18446611873974157022LLU,18302593684144914431LLU,69405593829341LLU},{18446744073709551615LLU,1152921504539615231LLU,2305843009213693919LLU,9204231738421673984LLU,18445618242505407936LLU,18158513699696992223LLU,9223371448477810687LLU,16428851619233193979LLU,18436470229539717603LLU,14105344401668571135LLU,70233393757247LLU},{18446744073692839935LLU,17293857753473220367LLU,18410187511109255167LLU,9799264345941606303LLU,17861272754899124221LLU,18446742422428581863LLU,10376187970999802883LLU,18235066073688834047LLU,18446607733411675775LLU,17651665225428237789LLU,69405597730636LLU},{18446744073709551615LLU,18446744073707978496LLU,18392140127250939903LLU,9254896134751516671LLU,18446744004990074943LLU,288195189640527359LLU,18446743936237173760LLU,4539909895071333823LLU,18446744072639512094LLU,4341404070087490764LLU,69405728294848LLU},{18442505456383488255LLU,18378064171204739071LLU,18437739071330516991LLU,18442170105354780671LLU,18446744073709551615LLU,288230374012616191LLU,15843625968255041536LLU,13763281936220944191LLU,18446717633827471359LLU,4341469986023489520LLU,57037030946812LLU},{18446744073709551615LLU,18446638520585419776LLU,18392700877979772927LLU,36028797018961919LLU,18374686479671623680LLU,18446708889337462783LLU,18446744069414715391LLU,9223370937343278591LLU,18446744065186721822LLU,18445622571849219279LLU,66244767108099LLU},{18446744073709551615LLU,18445618173601128447LLU,2305843007066144735LLU,18446673704965373952LLU,18446744073692773887LLU,65535LLU,18446744073709486080LLU,16645306421784543227LLU,18436610974480863207LLU,1125899906842623LLU,57058589999100LLU},{16140335777543224799LLU,16131607991127373823LLU,2304642067092979615LLU,0LLU,18446744073709551552LLU,18446744073709551615LLU,18446744073709551615LLU,17798227926391390203LLU,13687555254700740599LLU,18159638479413948411LLU,30747654029311LLU},{9221110889044244351LLU,9183947943163994111LLU,18441940300931595263LLU,18446744073709551615LLU,18446744073692773887LLU,65535LLU,18446742974197923840LLU,17293822569102704639LLU,18437736865865400303LLU,288230376151711743LLU,43903122013184LLU},{14374501308146941127LLU,14396452129193333759LLU,16427329956597374855LLU,18446744073709551615LLU,18446744073709551615LLU,6281585559563403263LLU,15693582350921234773LLU,17798226826879727449LLU,13687555254700740599LLU,18159638479413948411LLU,30747654029311LLU},{17834113752396431351LLU,14410989873740115968LLU,17293710349188433911LLU,36028797018961919LLU,18446744073709551552LLU,6318162063696855039LLU,18446744073709550933LLU,18374686479671754751LLU,18446744073709027358LLU,18158518095604350207LLU,32435054043135LLU},{17834113752396431351LLU,17870282153175023615LLU,16429131371925995511LLU,140737488355327LLU,18376938227676209088LLU,18446744073709551615LLU,1099511627775LLU,18374686479671623680LLU,11310146545464115198LLU,18446742259729278075LLU,32435054043135LLU}};

uint_fast8_t X[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[24][11] = {{18446744073709551615LLU,18446744073709551615LLU,16140901064495857663LLU,106286122620245LLU,18304505353838893440LLU,12165158514146202966LLU,8034419536205776554LLU,18374688131444431283LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[24];
    cnt[0] = 0;
    cnt[1] = 0;
    cnt[2] = 0;
    cnt[3] = 0;
    cnt[4] = 0;
    cnt[5] = 0;
    cnt[6] = 0;
    cnt[7] = 0;
    cnt[8] = 0;
    cnt[9] = 0;
    cnt[10] = 0;
    cnt[11] = 0;
    cnt[12] = 0;
    cnt[13] = 0;
    cnt[14] = 0;
    cnt[15] = 0;
    cnt[16] = 0;
    cnt[17] = 0;
    cnt[18] = 0;
    cnt[19] = 0;
    cnt[20] = 0;
    cnt[21] = 0;
    cnt[22] = 0;
    cnt[23] = 0;

    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[0]), "+r" (cnt[1]), "+r" (cnt[2]), "+r" (cnt[3])
            : "r" (buf[0]), "r" (buf[1]), "r" (buf[2]), "r" (buf[3]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[4]), "+r" (cnt[5]), "+r" (cnt[6]), "+r" (cnt[7])
            : "r" (buf[4]), "r" (buf[5]), "r" (buf[6]), "r" (buf[7]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[8]), "+r" (cnt[9]), "+r" (cnt[10]), "+r" (cnt[11])
            : "r" (buf[8]), "r" (buf[9]), "r" (buf[10]), "r" (buf[11]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[12]), "+r" (cnt[13]), "+r" (cnt[14]), "+r" (cnt[15])
            : "r" (buf[12]), "r" (buf[13]), "r" (buf[14]), "r" (buf[15]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[16]), "+r" (cnt[17]), "+r" (cnt[18]), "+r" (cnt[19])
            : "r" (buf[16]), "r" (buf[17]), "r" (buf[18]), "r" (buf[19]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[20]), "+r" (cnt[21]), "+r" (cnt[22]), "+r" (cnt[23])
            : "r" (buf[20]), "r" (buf[21]), "r" (buf[22]), "r" (buf[23]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17] + cnt[18] + cnt[19] + cnt[20] + cnt[21] + cnt[22] + cnt[23];
}

#elif UINTPTR_MAX == 0xffffffff // 32-bit
int counter (unsigned long long i)
{
  unsigned int i1 = i, i2 = i >> 32;
  i1 = i1 - ((i1 >> 1) & 0x55555555);
  i2 = i2 - ((i2 >> 1) & 0x55555555);
  i1 = (i1 & 0x33333333) + ((i1 >> 2) & 0x33333333);
  i2 = (i2 & 0x33333333) + ((i2 >> 2) & 0x33333333);
  i1 = (i1 + (i1 >> 4)) & 0xF0F0F0F;
  i2 = (i2 + (i2 >> 4)) & 0xF0F0F0F;
  return ((i1 + i2) * 0x1010101) >> 24;
}

#else
#error "this cpu doesn't seem to be 32-bit or 64-bit. I don't know how to deal with this."
#endif
void f(uint_fast8_t i, uint_fast8_t y0){
    if(y0){
        A[i][0] = A[i-1][0] & C[i][0];
        A[i][1] = A[i-1][1] & C[i][1];
        A[i][2] = A[i-1][2] & C[i][2];
        A[i][3] = A[i-1][3] & C[i][3];
        A[i][4] = A[i-1][4] & C[i][4];
        A[i][5] = A[i-1][5] & C[i][5];
        A[i][6] = A[i-1][6] & C[i][6];
        A[i][7] = A[i-1][7] & C[i][7];
        A[i][8] = A[i-1][8] & C[i][8];
        A[i][9] = A[i-1][9] & C[i][9];
        A[i][10] = A[i-1][10] & C[i][10];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];
        A[i][5] = A[i-1][5] & D[i][5];
        A[i][6] = A[i-1][6] & D[i][6];
        A[i][7] = A[i-1][7] & D[i][7];
        A[i][8] = A[i-1][8] & D[i][8];
        A[i][9] = A[i-1][9] & D[i][9];
        A[i][10] = A[i-1][10] & D[i][10];

    }
}

void printout(){
    sprintf(str, "[                        ,%5d]\n", this);
    str[1] = X[0] ^ 48;
    str[2] = X[1] ^ 48;
    str[3] = X[2] ^ 48;
    str[4] = X[3] ^ 48;
    str[5] = X[4] ^ 48;
    str[6] = X[5] ^ 48;
    str[7] = X[6] ^ 48;
    str[8] = X[7] ^ 48;
    str[9] = X[8] ^ 48;
    str[10] = X[9] ^ 48;
    str[11] = X[10] ^ 48;
    str[12] = X[11] ^ 48;
    str[13] = X[12] ^ 48;
    str[14] = X[13] ^ 48;
    str[15] = X[14] ^ 48;
    str[16] = X[15] ^ 48;
    str[17] = X[16] ^ 48;
    str[18] = X[17] ^ 48;
    str[19] = X[18] ^ 48;
    str[20] = X[19] ^ 48;
    str[21] = X[20] ^ 48;
    str[22] = X[21] ^ 48;
    str[23] = X[22] ^ 48;
    str[24] = X[23] ^ 48;

}


void checkifbest(){
    uint_fast64_t * thisbuf = A[maxpos];
    this = counter(thisbuf);

    if(this == best){
        printout();
        fwrite(str, 1, sizeof(str), fout);
    }

    if(this > best){
        printout();
        fwrite(str, 1, sizeof(str), fout);
        best = this;
    }

}

int r(){
    goto startnocarry;
    
    startnocarry:
        if(i == maxpos){
            if(X[i]){
                X[i] = 0;
                i--;
                goto startcarry;
            }else{
                f(i, 0);
                checkifbest();
                X[i] = 1;
                f(i, 1);
                checkifbest();
                X[i] = 0;
                i--;
                goto startcarry;
            }
        }else{
            f(i, X[i]);
            i++;
            goto startnocarry;
        }
        
    startcarry:
        if(X[i] && (i != endhere)){
            X[i] = 0;
            i--;
            goto startcarry;
        }else{
            if(i == endhere){
                goto end;
            }else{
                X[i] = 1;
                f(i, 1);
                i++;
                goto startnocarry;
            }
        }

    end:
        return 0;
}
int main(){
fout = fopener;
    fputs("[[0,1],[0,12],[0,15],[1,2],[1,5],[2,3],[2,14],[3,4],[3,7],[4,5],[4,8],[5,6],[6,7],[6,10],[7,8],[8,9],[9,10],[9,13],[10,11],[11,12],[11,15],[12,13],[13,14],[14,15]]\n", fout);
    if(endhere){
        uint_fast8_t bitpos = 0;
        uint_fast8_t thisbit;
        while(starthere){
            thisbit = starthere & 1;
            X[bitpos] = thisbit;
            f(bitpos, thisbit);
            bitpos++;
            starthere >>= 1;
        }
        i = endhere;
        r();
    }else{
        i = 0;
        r();
    }
    fwrite("FINISHED.", 1, 9, fout);
    fclose(fout);
    return 0;
}

