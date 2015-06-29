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
		LINECOMMENT=10, BLOCKCOMMENT=11, IDENTIFIER=12, WHITESPACE=13;
	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"T__0", "T__1", "T__2", "T__3", "T__4", "STRING", "CHOICE", "ARROW", "GOTO", 
		"LINECOMMENT", "BLOCKCOMMENT", "IDENTIFIER", "WHITESPACE"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'['", "']'", "'scene'", "'{'", "'}'", null, "'choice'", "'->'", 
		"'goto'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, null, "STRING", "CHOICE", "ARROW", "GOTO", 
		"LINECOMMENT", "BLOCKCOMMENT", "IDENTIFIER", "WHITESPACE"
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
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\2\17}\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\3\2\3\2\3\3\3\3\3\4\3\4\3\4\3\4\3\4\3\4"+
		"\3\5\3\5\3\6\3\6\3\7\3\7\3\7\3\7\7\7\60\n\7\f\7\16\7\63\13\7\3\7\3\7\3"+
		"\7\3\7\3\7\7\7:\n\7\f\7\16\7=\13\7\3\7\6\7@\n\7\r\7\16\7A\3\b\3\b\3\b"+
		"\3\b\3\b\3\b\3\b\3\t\3\t\3\t\3\n\3\n\3\n\3\n\3\n\3\13\3\13\3\13\3\13\7"+
		"\13W\n\13\f\13\16\13Z\13\13\3\13\3\13\3\f\3\f\3\f\3\f\7\fb\n\f\f\f\16"+
		"\fe\13\f\3\f\3\f\3\f\3\f\3\f\3\r\6\rm\n\r\r\r\16\rn\3\r\7\rr\n\r\f\r\16"+
		"\ru\13\r\3\16\6\16x\n\16\r\16\16\16y\3\16\3\16\3c\2\17\3\3\5\4\7\5\t\6"+
		"\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\3\2\b\3\2$$\3\2))\3\2"+
		"\f\f\5\2C\\aac|\6\2\62;C\\aac|\4\2\13\f\"\"\u0087\2\3\3\2\2\2\2\5\3\2"+
		"\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21"+
		"\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2"+
		"\2\2\3\35\3\2\2\2\5\37\3\2\2\2\7!\3\2\2\2\t\'\3\2\2\2\13)\3\2\2\2\r?\3"+
		"\2\2\2\17C\3\2\2\2\21J\3\2\2\2\23M\3\2\2\2\25R\3\2\2\2\27]\3\2\2\2\31"+
		"l\3\2\2\2\33w\3\2\2\2\35\36\7]\2\2\36\4\3\2\2\2\37 \7_\2\2 \6\3\2\2\2"+
		"!\"\7u\2\2\"#\7e\2\2#$\7g\2\2$%\7p\2\2%&\7g\2\2&\b\3\2\2\2\'(\7}\2\2("+
		"\n\3\2\2\2)*\7\177\2\2*\f\3\2\2\2+\61\7$\2\2,\60\n\2\2\2-.\7^\2\2.\60"+
		"\7$\2\2/,\3\2\2\2/-\3\2\2\2\60\63\3\2\2\2\61/\3\2\2\2\61\62\3\2\2\2\62"+
		"\64\3\2\2\2\63\61\3\2\2\2\64@\7$\2\2\65;\7)\2\2\66:\n\3\2\2\678\7^\2\2"+
		"8:\7)\2\29\66\3\2\2\29\67\3\2\2\2:=\3\2\2\2;9\3\2\2\2;<\3\2\2\2<>\3\2"+
		"\2\2=;\3\2\2\2>@\7)\2\2?+\3\2\2\2?\65\3\2\2\2@A\3\2\2\2A?\3\2\2\2AB\3"+
		"\2\2\2B\16\3\2\2\2CD\7e\2\2DE\7j\2\2EF\7q\2\2FG\7k\2\2GH\7e\2\2HI\7g\2"+
		"\2I\20\3\2\2\2JK\7/\2\2KL\7@\2\2L\22\3\2\2\2MN\7i\2\2NO\7q\2\2OP\7v\2"+
		"\2PQ\7q\2\2Q\24\3\2\2\2RS\7\61\2\2ST\7\61\2\2TX\3\2\2\2UW\n\4\2\2VU\3"+
		"\2\2\2WZ\3\2\2\2XV\3\2\2\2XY\3\2\2\2Y[\3\2\2\2ZX\3\2\2\2[\\\b\13\2\2\\"+
		"\26\3\2\2\2]^\7\61\2\2^_\7,\2\2_c\3\2\2\2`b\13\2\2\2a`\3\2\2\2be\3\2\2"+
		"\2cd\3\2\2\2ca\3\2\2\2df\3\2\2\2ec\3\2\2\2fg\7,\2\2gh\7\61\2\2hi\3\2\2"+
		"\2ij\b\f\2\2j\30\3\2\2\2km\t\5\2\2lk\3\2\2\2mn\3\2\2\2nl\3\2\2\2no\3\2"+
		"\2\2os\3\2\2\2pr\t\6\2\2qp\3\2\2\2ru\3\2\2\2sq\3\2\2\2st\3\2\2\2t\32\3"+
		"\2\2\2us\3\2\2\2vx\t\7\2\2wv\3\2\2\2xy\3\2\2\2yw\3\2\2\2yz\3\2\2\2z{\3"+
		"\2\2\2{|\b\16\2\2|\34\3\2\2\2\17\2/\619;?AXcnqsy\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}