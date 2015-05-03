// Generated from Fabula.g4 by ANTLR 4.5
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class FabulaLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.5", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, STRING=6, CHOICE=7, ARROW=8, GOTO=9, 
		LINECOMMENT=10, BLOCKCOMMENT=11, IDENTIFIER=12, WHITESPACE=13, A=14, B=15, 
		C=16, D=17, E=18, F=19, G=20, H=21, I=22, J=23, K=24, L=25, M=26, N=27, 
		O=28, P=29, Q=30, R=31, S=32, T=33, U=34, V=35, W=36, X=37, Y=38, Z=39;
	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"T__0", "T__1", "T__2", "T__3", "T__4", "STRING", "CHOICE", "ARROW", "GOTO", 
		"LINECOMMENT", "BLOCKCOMMENT", "IDENTIFIER", "WHITESPACE", "A", "B", "C", 
		"D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", 
		"R", "S", "T", "U", "V", "W", "X", "Y", "Z"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'['", "']'", "'scene'", "'{'", "'}'", null, "'choice'", "'->'", 
		"'goto'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, null, "STRING", "CHOICE", "ARROW", "GOTO", 
		"LINECOMMENT", "BLOCKCOMMENT", "IDENTIFIER", "WHITESPACE", "A", "B", "C", 
		"D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", 
		"R", "S", "T", "U", "V", "W", "X", "Y", "Z"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public FabulaLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Fabula.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\2)\u00e5\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\3\2\3\2\3\3\3\3\3\4"+
		"\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\7\3\7\7\7d\n\7\f\7\16\7"+
		"g\13\7\3\7\3\7\3\7\3\7\3\7\7\7n\n\7\f\7\16\7q\13\7\3\7\6\7t\n\7\r\7\16"+
		"\7u\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\t\3\t\3\t\3\n\3\n\3\n\3\n\3\n\3\13\3"+
		"\13\3\13\3\13\7\13\u008b\n\13\f\13\16\13\u008e\13\13\3\13\3\13\3\f\3\f"+
		"\3\f\3\f\7\f\u0096\n\f\f\f\16\f\u0099\13\f\3\f\3\f\3\f\3\f\3\f\3\r\6\r"+
		"\u00a1\n\r\r\r\16\r\u00a2\3\r\7\r\u00a6\n\r\f\r\16\r\u00a9\13\r\3\16\6"+
		"\16\u00ac\n\16\r\16\16\16\u00ad\3\16\3\16\3\17\3\17\3\20\3\20\3\21\3\21"+
		"\3\22\3\22\3\23\3\23\3\24\3\24\3\25\3\25\3\26\3\26\3\27\3\27\3\30\3\30"+
		"\3\31\3\31\3\32\3\32\3\33\3\33\3\34\3\34\3\35\3\35\3\36\3\36\3\37\3\37"+
		"\3 \3 \3!\3!\3\"\3\"\3#\3#\3$\3$\3%\3%\3&\3&\3\'\3\'\3(\3(\3\u0097\2)"+
		"\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20"+
		"\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34\67\359\36;\37"+
		"= ?!A\"C#E$G%I&K\'M(O)\3\2\"\3\2$$\3\2))\3\2\f\f\5\2C\\aac|\6\2\62;C\\"+
		"aac|\4\2\13\f\"\"\4\2CCcc\4\2DDdd\4\2EEee\4\2FFff\4\2GGgg\4\2HHhh\4\2"+
		"IIii\4\2JJjj\4\2KKkk\4\2LLll\4\2MMmm\4\2NNnn\4\2OOoo\4\2PPpp\4\2QQqq\4"+
		"\2RRrr\4\2SSss\4\2TTtt\4\2UUuu\4\2VVvv\4\2WWww\4\2XXxx\4\2YYyy\4\2ZZz"+
		"z\4\2[[{{\4\2\\\\||\u00ef\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2"+
		"\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2"+
		"\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3"+
		"\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2"+
		"\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67"+
		"\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2"+
		"\2\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2M\3\2\2\2\2O\3\2\2\2"+
		"\3Q\3\2\2\2\5S\3\2\2\2\7U\3\2\2\2\t[\3\2\2\2\13]\3\2\2\2\rs\3\2\2\2\17"+
		"w\3\2\2\2\21~\3\2\2\2\23\u0081\3\2\2\2\25\u0086\3\2\2\2\27\u0091\3\2\2"+
		"\2\31\u00a0\3\2\2\2\33\u00ab\3\2\2\2\35\u00b1\3\2\2\2\37\u00b3\3\2\2\2"+
		"!\u00b5\3\2\2\2#\u00b7\3\2\2\2%\u00b9\3\2\2\2\'\u00bb\3\2\2\2)\u00bd\3"+
		"\2\2\2+\u00bf\3\2\2\2-\u00c1\3\2\2\2/\u00c3\3\2\2\2\61\u00c5\3\2\2\2\63"+
		"\u00c7\3\2\2\2\65\u00c9\3\2\2\2\67\u00cb\3\2\2\29\u00cd\3\2\2\2;\u00cf"+
		"\3\2\2\2=\u00d1\3\2\2\2?\u00d3\3\2\2\2A\u00d5\3\2\2\2C\u00d7\3\2\2\2E"+
		"\u00d9\3\2\2\2G\u00db\3\2\2\2I\u00dd\3\2\2\2K\u00df\3\2\2\2M\u00e1\3\2"+
		"\2\2O\u00e3\3\2\2\2QR\7]\2\2R\4\3\2\2\2ST\7_\2\2T\6\3\2\2\2UV\7u\2\2V"+
		"W\7e\2\2WX\7g\2\2XY\7p\2\2YZ\7g\2\2Z\b\3\2\2\2[\\\7}\2\2\\\n\3\2\2\2]"+
		"^\7\177\2\2^\f\3\2\2\2_e\7$\2\2`d\n\2\2\2ab\7^\2\2bd\7$\2\2c`\3\2\2\2"+
		"ca\3\2\2\2dg\3\2\2\2ec\3\2\2\2ef\3\2\2\2fh\3\2\2\2ge\3\2\2\2ht\7$\2\2"+
		"io\7)\2\2jn\n\3\2\2kl\7^\2\2ln\7)\2\2mj\3\2\2\2mk\3\2\2\2nq\3\2\2\2om"+
		"\3\2\2\2op\3\2\2\2pr\3\2\2\2qo\3\2\2\2rt\7)\2\2s_\3\2\2\2si\3\2\2\2tu"+
		"\3\2\2\2us\3\2\2\2uv\3\2\2\2v\16\3\2\2\2wx\7e\2\2xy\7j\2\2yz\7q\2\2z{"+
		"\7k\2\2{|\7e\2\2|}\7g\2\2}\20\3\2\2\2~\177\7/\2\2\177\u0080\7@\2\2\u0080"+
		"\22\3\2\2\2\u0081\u0082\7i\2\2\u0082\u0083\7q\2\2\u0083\u0084\7v\2\2\u0084"+
		"\u0085\7q\2\2\u0085\24\3\2\2\2\u0086\u0087\7\61\2\2\u0087\u0088\7\61\2"+
		"\2\u0088\u008c\3\2\2\2\u0089\u008b\n\4\2\2\u008a\u0089\3\2\2\2\u008b\u008e"+
		"\3\2\2\2\u008c\u008a\3\2\2\2\u008c\u008d\3\2\2\2\u008d\u008f\3\2\2\2\u008e"+
		"\u008c\3\2\2\2\u008f\u0090\b\13\2\2\u0090\26\3\2\2\2\u0091\u0092\7\61"+
		"\2\2\u0092\u0093\7,\2\2\u0093\u0097\3\2\2\2\u0094\u0096\13\2\2\2\u0095"+
		"\u0094\3\2\2\2\u0096\u0099\3\2\2\2\u0097\u0098\3\2\2\2\u0097\u0095\3\2"+
		"\2\2\u0098\u009a\3\2\2\2\u0099\u0097\3\2\2\2\u009a\u009b\7,\2\2\u009b"+
		"\u009c\7\61\2\2\u009c\u009d\3\2\2\2\u009d\u009e\b\f\2\2\u009e\30\3\2\2"+
		"\2\u009f\u00a1\t\5\2\2\u00a0\u009f\3\2\2\2\u00a1\u00a2\3\2\2\2\u00a2\u00a0"+
		"\3\2\2\2\u00a2\u00a3\3\2\2\2\u00a3\u00a7\3\2\2\2\u00a4\u00a6\t\6\2\2\u00a5"+
		"\u00a4\3\2\2\2\u00a6\u00a9\3\2\2\2\u00a7\u00a5\3\2\2\2\u00a7\u00a8\3\2"+
		"\2\2\u00a8\32\3\2\2\2\u00a9\u00a7\3\2\2\2\u00aa\u00ac\t\7\2\2\u00ab\u00aa"+
		"\3\2\2\2\u00ac\u00ad\3\2\2\2\u00ad\u00ab\3\2\2\2\u00ad\u00ae\3\2\2\2\u00ae"+
		"\u00af\3\2\2\2\u00af\u00b0\b\16\2\2\u00b0\34\3\2\2\2\u00b1\u00b2\t\b\2"+
		"\2\u00b2\36\3\2\2\2\u00b3\u00b4\t\t\2\2\u00b4 \3\2\2\2\u00b5\u00b6\t\n"+
		"\2\2\u00b6\"\3\2\2\2\u00b7\u00b8\t\13\2\2\u00b8$\3\2\2\2\u00b9\u00ba\t"+
		"\f\2\2\u00ba&\3\2\2\2\u00bb\u00bc\t\r\2\2\u00bc(\3\2\2\2\u00bd\u00be\t"+
		"\16\2\2\u00be*\3\2\2\2\u00bf\u00c0\t\17\2\2\u00c0,\3\2\2\2\u00c1\u00c2"+
		"\t\20\2\2\u00c2.\3\2\2\2\u00c3\u00c4\t\21\2\2\u00c4\60\3\2\2\2\u00c5\u00c6"+
		"\t\22\2\2\u00c6\62\3\2\2\2\u00c7\u00c8\t\23\2\2\u00c8\64\3\2\2\2\u00c9"+
		"\u00ca\t\24\2\2\u00ca\66\3\2\2\2\u00cb\u00cc\t\25\2\2\u00cc8\3\2\2\2\u00cd"+
		"\u00ce\t\26\2\2\u00ce:\3\2\2\2\u00cf\u00d0\t\27\2\2\u00d0<\3\2\2\2\u00d1"+
		"\u00d2\t\30\2\2\u00d2>\3\2\2\2\u00d3\u00d4\t\31\2\2\u00d4@\3\2\2\2\u00d5"+
		"\u00d6\t\32\2\2\u00d6B\3\2\2\2\u00d7\u00d8\t\33\2\2\u00d8D\3\2\2\2\u00d9"+
		"\u00da\t\34\2\2\u00daF\3\2\2\2\u00db\u00dc\t\35\2\2\u00dcH\3\2\2\2\u00dd"+
		"\u00de\t\36\2\2\u00deJ\3\2\2\2\u00df\u00e0\t\37\2\2\u00e0L\3\2\2\2\u00e1"+
		"\u00e2\t \2\2\u00e2N\3\2\2\2\u00e3\u00e4\t!\2\2\u00e4P\3\2\2\2\17\2ce"+
		"mosu\u008c\u0097\u00a2\u00a5\u00a7\u00ad\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}