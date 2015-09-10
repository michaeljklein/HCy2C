#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_20_1208_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 19;
static uint_fast32_t endhere = 0;
char str[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[20][18] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,9007199254740991LLU,0LLU,0LLU,0LLU,18446744073692774400LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,8191LLU,0LLU,0LLU,18446744072635809792LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU,0LLU,0LLU,18437736874454810624LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{0LLU,0LLU,0LLU,18446744073709543424LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{9223372036854775808LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18445618175950192639LLU,18446469160352350207LLU,18432881429361694719LLU,18446742132250065663LLU,17788653099810808831LLU,17288746909881597951LLU,9079186419364126646LLU,16252671LLU,18446744073705357312LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{9223372036854775807LLU,0LLU,18446744073709551615LLU,18446744065119633407LLU,9223372034757353467LLU,18446675345374304249LLU,18446744073373794303LLU,18446744073709551615LLU,18446744073709551615LLU,16104872267476893695LLU,8069254229236850431LLU,15996715507020988155LLU,17288753339462318975LLU,18446744073699945903LLU,4194303LLU,18446744073705357312LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,0LLU,8589926400LLU,18419722475945328639LLU,18446744073709551359LLU,1125899898453967LLU,18446744073709027328LLU,4611685812267909103LLU,17365880163140632575LLU,18302487598389526527LLU,18157387797650997127LLU,18446744073709305839LLU,18446744073709551612LLU,18446744073709551615LLU,4194303LLU,18446744073709547520LLU,4194303LLU},{18446744069414584321LLU,16140887870289199103LLU,18374686471148797951LLU,18446744073709550589LLU,0LLU,18446744073709518848LLU,11529212851340181503LLU,17870230536257994751LLU,18446744072629518335LLU,18446180569705316336LLU,18446744073709551615LLU,18446744073695920255LLU,18419722458631241727LLU,18410715276707168255LLU,18446462598195970047LLU,18446711088360701948LLU,18446744073676001263LLU,4194303LLU},{9223372041149743103LLU,18302628872747745023LLU,16136397464868486913LLU,18446744073709551551LLU,18446744073709551615LLU,32767LLU,18438864972311166976LLU,18445407067565977599LLU,18437732751286189983LLU,1152911608968642559LLU,18446744073709544960LLU,18446744073709551615LLU,18446730845209231359LLU,36028797018963871LLU,18392696480122011648LLU,18446744073583721471LLU,18446743798865199102LLU,4194303LLU},{18392683285969887231LLU,18446744071562067968LLU,18446730878495883231LLU,18445617624030150655LLU,17906311843144531455LLU,18437723680298500091LLU,18446744073709419583LLU,524287LLU,18446744056529682432LLU,18446744073709551615LLU,18446727581035118575LLU,18412967076470685695LLU,18446744073709551615LLU,17870072214905159679LLU,18437736874458980351LLU,18437736840095072255LLU,18446603585326153727LLU,4194303LLU},{18446462598732709887LLU,2147483647LLU,17872534846341898239LLU,18230571283022610431LLU,18446726479912828927LLU,17870230542700511231LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU,18437736874454810624LLU,18446744072904212479LLU,18446742424375001087LLU,18446743657097986047LLU,9223372032559808511LLU,9007199254740991LLU,9799269837053100032LLU,18374827216018989055LLU,4194303LLU},{18445618044953690111LLU,9208700153425231857LLU,864119262149607423LLU,17870177768289857535LLU,18446744073709551615LLU,11529215045531664383LLU,18446744073608888191LLU,11529215043921772126LLU,18446744073457893375LLU,2251798745185823LLU,0LLU,18446744073709551615LLU,18446744073709551615LLU,13871086852301127679LLU,18445054673828174847LLU,4458317340490064115LLU,69787297914025976LLU,4194303LLU},{18446744073709027267LLU,17816238992002120591LLU,18428729675183026687LLU,17293822517563096816LLU,18374475373439074305LLU,18446744073709548543LLU,17852268922896646143LLU,18433228878928394751LLU,17581921003859079423LLU,18446638384228073471LLU,18446744073709551615LLU,0LLU,18446744073709549568LLU,18437657707486904319LLU,13618858799258402815LLU,17293821984046981119LLU,18446595639630097799LLU,4194048LLU},{18302621326424142399LLU,18446673636245897215LLU,18446671642976260083LLU,18441815856435429375LLU,1152921440148799487LLU,18444631912409464831LLU,18410715276690556927LLU,18446744073709551613LLU,18444632461628407807LLU,18446744073709543933LLU,18446744073709551615LLU,18446744073709551615LLU,2047LLU,4610840633555288064LLU,17564038546744835984LLU,18406486401399914446LLU,18432388849427488767LLU,4129023LLU},{13798889345408565247LLU,17329358783301804127LLU,18446744073675997184LLU,18446726487688937471LLU,18446744073709551615LLU,18302699202838265855LLU,17294372324371332591LLU,18302910154451976191LLU,13835058040248729599LLU,18446605432164771839LLU,18446744073709551615LLU,18418596507453226983LLU,18445618720337246447LLU,18446744073694871550LLU,18442240231416528413LLU,18446742974201266015LLU,18437722425513738239LLU,3964028LLU},{18446744071545225599LLU,1143913824290086907LLU,18445618173836263423LLU,18410732864545226751LLU,18149502102402498559LLU,18446744073709534975LLU,1152920379325415423LLU,144115187975192512LLU,18318954365563207660LLU,18221704829024075775LLU,2161714077209001983LLU,18446744073709551615LLU,16142026964377337855LLU,18446739933361071101LLU,15564368019269353471LLU,18158514797066317823LLU,9006583253332574207LLU,3396607LLU},{17573186457311444979LLU,18445044769898889215LLU,1125899906842623LLU,36028796414976000LLU,18426482273432895367LLU,144115188071923655LLU,18446550181704105948LLU,18446744073709027391LLU,8214563383861575679LLU,3746994889968582647LLU,18430840668839477244LLU,4323314973506789791LLU,18446744073709551614LLU,18228288705355841535LLU,13835058055281897983LLU,288230376151711487LLU,15254677092805242880LLU,1048531LLU},{18445485850159480831LLU,18446744073709545463LLU,4611685907261620223LLU,17870160450981593085LLU,2251799813685247LLU,11387351605733982208LLU,12754183287035920383LLU,18320608097757822719LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU,18446744006050193383LLU,18418614151044628479LLU,14087294818787000319LLU,18446743936069270141LLU,18446505496866193407LLU,1152893467027832809LLU,3997181LLU},{9232379236108930895LLU,18446744073709158335LLU,16139777363612267279LLU,17258356670497030131LLU,18446528638148395135LLU,18446744073709551615LLU,18441184924665905155LLU,9223227176197815235LLU,18446744073709551612LLU,18230571291595767807LLU,18446744073676514819LLU,140737488355327LLU,16176916633015416832LLU,18446731959888510975LLU,18446742961308831743LLU,18163017296279240703LLU,18302586563025960862LLU,3405583LLU},{18439983709283153655LLU,18446744071562592255LLU,18446742424173625335LLU,2305561396782293007LLU,18444773697033076639LLU,9221673360106192895LLU,18410680023599022076LLU,18446744073709029373LLU,18446744056529682435LLU,17870283321406128127LLU,18446744006063800316LLU,18446605535210891199LLU,2305843009213693951LLU,18302610640528736256LLU,18437739073478064051LLU,18443361963040833535LLU,17870212948097986687LLU,987127LLU}};

static uint_fast64_t D[20][18] = {{10821216411353439741LLU,11093741614777707774LLU,17640278668979600989LLU,4085862707205534527LLU,17517821395944341502LLU,16636160684064718043LLU,1856608950115236237LLU,16641662640249425831LLU,4386498949277400909LLU,18445027186297765862LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551614LLU,7353002458931843841LLU,7725334430901034494LLU,18446744073709546710LLU,18446744073709551615LLU,18446744073709551615LLU,16590135125178580991LLU,6750602989971124312LLU,16982150585031284475LLU,18435306625853993695LLU,15338672353674411007LLU,17242566871536893950LLU,8789688494167957158LLU,18446744073706920696LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{7625527662356111875LLU,18446744073709551615LLU,11527875047538467747LLU,14360881366504030185LLU,8067841850629921619LLU,6752441109687424949LLU,18446744073371564027LLU,18446744073709551615LLU,18446744073709551615LLU,10412322338480586751LLU,8048847223593879258LLU,11096656097635128451LLU,14937852704519615357LLU,18446744073699945903LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709543423LLU,11307824900844840109LLU,13504886353666960238LLU,18446744072463273590LLU,13501222517198553087LLU,15524838613110417846LLU,8047576070496308537LLU,13505968570150812965LLU,8554265178247080829LLU,13165946948731530715LLU,18446744073705011031LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,8191LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,13501228041075949567LLU,1692209722950090214LLU,17306977054794575807LLU,4611430879652872191LLU,17924219863501373313LLU,16709758691661314559LLU,18446744073696913383LLU,1643026641208737791LLU,402472269097651291LLU,18446744073709547699LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16108662103663933103LLU,13504887734650011247LLU,1060630470LLU,18446744073709027328LLU,18446744073709551615LLU,9223372036854775807LLU,18181030726949928885LLU,9221388047579196415LLU,4377384488594575330LLU,12170626369666940924LLU,18446744073708724249LLU,18044271804612083711LLU,18446744073709551436LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4395513234174037497LLU,18446673964391252984LLU,18446744073205980799LLU,18446463636474953727LLU,18430452058080379839LLU,14987977468004997241LLU,16427157817275646063LLU,14404763408010542719LLU,18446743527301840671LLU,6276117704057355295LLU,16803717432501641190LLU,18446744073709368228LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,8965294651743731229LLU,14692403054494351104LLU,18446744073709547415LLU,18446744073709551615LLU,18446744073709551615LLU,18438862774361653247LLU,2303871653576958808LLU,18446739686350126978LLU,2236303509612447LLU,18446744073709551104LLU,17878039825144086527LLU,16429114257555175663LLU,18446744073694871426LLU,18378618842193592319LLU,3861238546012239963LLU,18446743798865196734LLU,4194303LLU},{18446744073709551615LLU,14384480476515505123LLU,9097271238714416639LLU,18446744073709549820LLU,18446744073709551615LLU,18446744073709551615LLU,9673731999591825407LLU,17370383747232185599LLU,232471942475709695LLU,18445653349853298672LLU,2161450133516468223LLU,18446744073708503040LLU,18410855739040890879LLU,18446744073709290493LLU,1656822803627769855LLU,14987944811320283132LLU,18446744073675999715LLU,4194303LLU},{16861017193527950235LLU,18446744073709551615LLU,17871197631756093371LLU,18180813889313177599LLU,14987947111410971623LLU,17383472345325501991LLU,18446744073694078975LLU,18446744073709551615LLU,18446744073709551615LLU,4179340454199820287LLU,18160624758813618079LLU,4323453451833768399LLU,18446744069414586336LLU,3379663166404296703LLU,18446744073708731615LLU,9402510652171354111LLU,18374827216018989055LLU,4194303LLU},{18380284316675982951LLU,18446744073709551615LLU,11529199066910604231LLU,14409512319123980265LLU,17871479057473338399LLU,2288391302927089663LLU,18446744073709550594LLU,18446744073709551615LLU,18446744073709551615LLU,17798225727368200191LLU,18446726542723119072LLU,18410840613495703479LLU,2026483441335271423LLU,17437663377018060796LLU,18446744073709519673LLU,18432023755883544575LLU,18446603585326153548LLU,4194303LLU},{13578063704963939841LLU,15275923941610994175LLU,18347559328321306879LLU,13756244793072482943LLU,18446744073675997184LLU,17868075502057553919LLU,16077177763756212717LLU,17854362393035841527LLU,13832810643848163453LLU,18446057428697710588LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446743936287375359LLU,17365853706141990815LLU,17257787157967798270LLU,18437310263943171583LLU,4154982LLU},{18446742976225735167LLU,4467447405455765247LLU,18009892719418146801LLU,9078708188007229375LLU,278079617426784255LLU,18446742974197939967LLU,9077001535681986559LLU,10303004494400188412LLU,18365678386803490767LLU,18438852878756995087LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,35183547455111167LLU,18427040275583991792LLU,13830589502560665539LLU,7414596243822737407LLU,4168191LLU},{15544649101541072895LLU,18375238975674646400LLU,575603127839489887LLU,16409981794704654320LLU,18320394518429433855LLU,10295189165750350299LLU,12965413850163576607LLU,18446739675663562767LLU,8214563383861575679LLU,18446743936271122423LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18437657709617610751LLU,13835058038105431039LLU,9070249065408495871LLU,11096865279205703552LLU,4194201LLU},{17582052919480418815LLU,18437726016752320507LLU,18446744073709551615LLU,18446744073606791167LLU,18444492273929420799LLU,18446743246924218367LLU,18446603207269449599LLU,18446740766458904575LLU,17296074368710610943LLU,18446744068407950963LLU,18446744004990075391LLU,576460752303415423LLU,18446744073543876606LLU,8971135410788687999LLU,10374780604283215863LLU,18446744073709529077LLU,17361939238587793407LLU,2875359LLU},{18437737973563785203LLU,18408604204164710367LLU,18446744073709551615LLU,18446744072895856639LLU,18374686479646392193LLU,1099511624640LLU,18446677828133978108LLU,18446743814396706815LLU,18446635205146964927LLU,1152921375720087551LLU,18429011150176780284LLU,18446603336222244863LLU,18446744069681971199LLU,18434288732841705375LLU,18259822695577284623LLU,18446744073709451839LLU,16113737621678587903LLU,1998832LLU},{13799028981221031807LLU,71987156573749375LLU,18446744073709551615LLU,18446744067266117631LLU,4179340454197841407LLU,18446744008865583103LLU,18446180023304953087LLU,4398046511103LLU,18444632461628407804LLU,18437737011893756413LLU,288213883477294703LLU,18412967076503453695LLU,16140901068790822943LLU,15545722199129194495LLU,17564036364899368956LLU,18446744073705488334LLU,9223305911385178111LLU,3534975LLU},{17361095088536551423LLU,18446741876800356287LLU,18412842556812427263LLU,13756245061682069015LLU,18446744073709551615LLU,17870256106345857023LLU,18446497783102833661LLU,9223227176197784561LLU,17293822586282311680LLU,18446744073709551615LLU,18446744073709551615LLU,35904002348548095LLU,16429131303175192574LLU,9223372036854767619LLU,9232239585247395831LLU,16660503871503728639LLU,18444632971320229055LLU,2869191LLU},{18446744073204006911LLU,18444494470805186551LLU,8682940081566605311LLU,9079253549291790847LLU,575317259379998719LLU,18446744073709551552LLU,18194542013540466687LLU,18320608097757331199LLU,1152921487427239935LLU,18446744073705357312LLU,18428747206451216383LLU,18446744073709551615LLU,18445758632151711743LLU,18442521876027678719LLU,9214505437448110079LLU,11529214829172620800LLU,14377741810375414779LLU,1981951LLU},{10376187915867733983LLU,2251799813685247LLU,18445758836099774271LLU,18419638871185686527LLU,18446740224345097215LLU,18320608099267739711LLU,12965008438657548287LLU,18446744073709551567LLU,18446744073709551615LLU,18293621686383149055LLU,18014398480117279LLU,18446744013570637807LLU,18446744073709549569LLU,14956452161863548927LLU,18446744073705881343LLU,18230412136679473663LLU,4431541827148972031LLU,3538749LLU}};

uint_fast8_t X[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[20][18] = {{10821216411353439741LLU,11093741614777707774LLU,17640278668979600989LLU,4085862707205534527LLU,17517821395944341502LLU,16636160684064718043LLU,1856608950115236237LLU,16641662640249425831LLU,4386498949277400909LLU,18445027186297765862LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[20];
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


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17] + cnt[18] + cnt[19];
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
        A[i][11] = A[i-1][11] & C[i][11];
        A[i][12] = A[i-1][12] & C[i][12];
        A[i][13] = A[i-1][13] & C[i][13];
        A[i][14] = A[i-1][14] & C[i][14];
        A[i][15] = A[i-1][15] & C[i][15];
        A[i][16] = A[i-1][16] & C[i][16];
        A[i][17] = A[i-1][17] & C[i][17];

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
        A[i][11] = A[i-1][11] & D[i][11];
        A[i][12] = A[i-1][12] & D[i][12];
        A[i][13] = A[i-1][13] & D[i][13];
        A[i][14] = A[i-1][14] & D[i][14];
        A[i][15] = A[i-1][15] & D[i][15];
        A[i][16] = A[i-1][16] & D[i][16];
        A[i][17] = A[i-1][17] & D[i][17];

    }
}

void printout(){
    sprintf(str, "[                    ,%5d]\n", this);
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
    fputs("[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,5],[2,6],[2,7],[3,8],[3,9],[4,6],[4,7],[4,8],[5,6],[5,7],[5,8],[6,9],[7,9],[8,9]]\n", fout);
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
