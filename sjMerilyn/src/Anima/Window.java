package Anima;
import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.event.*;

public class Window extends JFrame
{
	private static final long serialVersionUID = 1L;
	private static Listener listener;
	private TextListener textListener;
	public JTextArea textarea;
	ShortcutKeyListener keyListener;
	public static final String defaultWndowTitle = "Merilyn";
	public ThisWindowAdapter windowAdapter;
	public String openedFilePath="null";
	public String openedFileName = "";
	private boolean fileEdited=false;
	
	public final String menuItems [] = {"File","New","Open","Save","Save As","Quit","","Edit","Copy","Cut","Paste","","Help","About",""};
	public final String menuTooltips [] = {"","Create a new file", "Open an existing file","Save the file","Select how to save the file",
			"Quit the application","","","Copy the selected text","Cut the selected text","Paste the selected text","","","About Merilyn"};
	//'-' ignored.
	public final int ctrlMenuShortcuts [] = {0,KeyEvent.VK_N,KeyEvent.VK_O,KeyEvent.VK_S,KeyEvent.VK_U,0,0,0,0,0,0,0,0,KeyEvent.VK_P,0};
	
	
	boolean initialise()
	{
		listener = new Listener(this);
		textListener=new TextListener();
		windowAdapter = new ThisWindowAdapter(this);
		
		setTitle("Merilyn");
		setSize(800,600);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(DO_NOTHING_ON_CLOSE); //Instead give control to anonymous window listener.
		setIconImage((new ImageIcon("res/icon_100.png")).getImage());
		
		JMenuBar menubar = new JMenuBar();
		
		//Initialise menu:
		
		keyListener = new ShortcutKeyListener(this);
		
		for (int i = 0; i < menuItems.length; ++i)
		{
			JMenu menu = new JMenu(menuItems[i]);
			menubar.add(menu);
			++i;
			for (; i < menuItems.length && !menuItems[i].equals(""); ++i)
			{
				JMenuItem menuitem = new JMenuItem(menuItems[i]);
				menuitem.addActionListener(listener);
				menuitem.setToolTipText(menuTooltips[i]);
				menu.add(menuitem);
			}
		}
		
		

		setJMenuBar(menubar);

		//Text area:
		textarea = new JTextArea(5,50);
		textarea.setText("Hello World!");
		textarea.setFont(new Font("Serif",Font.BOLD,12));
		textarea.setLineWrap(true);
		textarea.setWrapStyleWord(true);
		textarea.getDocument().addDocumentListener(textListener);
		textarea.addKeyListener(keyListener);
		add(textarea);
		
		JScrollPane scrollpane = new JScrollPane(textarea,
					JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
		add(scrollpane,BorderLayout.CENTER);
		
		BasicActions.newFile(this);
		
		//Window listener for closing operation:
		addWindowListener(windowAdapter);
		
		
		
		setVisible(true);
		return true;
	}
	
	void setFileEdited(boolean edited)
	{
		fileEdited=edited;
		String newTitle = new String(defaultWndowTitle+" - " + openedFileName);
		if (edited)
		{
			newTitle+="*";
		}
		setTitle(newTitle);
	}
	
	boolean getFileEdited()
	{
		return fileEdited;
	}
	
	void evaluateMenuButton(String cm)
	{
		if (cm.equals("Open"))
		{
			BasicActions.openFile(this);
		}
		else if (cm.equals("New"))
		{
			BasicActions.newFile(this);
		}
		else if (cm.equals("Save"))
		{
			BasicActions.saveFile(this);
		}
		else if (cm.equals("Save As"))
		{
			BasicActions.saveAsFile(this);
		}
		else if (cm.equals("Quit"))
		{
			System.exit(0);
		}
		else if (cm.equals("Copy"))
		{
			BasicActions.copy(this);
		}
		else if (cm.equals("Cut"))
		{
			BasicActions.cut(this);
		}
		else if (cm.equals("Paste"))
		{
			BasicActions.paste(this);
		}
		else if (cm.equals("About"))
		{
			BasicActions.about(this);
		}
		else
		{
			assert false;
		}
	}
	
	class ThisWindowAdapter extends WindowAdapter
	{
		Window window;
		
		ThisWindowAdapter(Window window_)
		{
			window=window_;
		}
		
		  @Override
		  public void windowClosing(WindowEvent we)
		  { 
		   if (window.getFileEdited())
		   {
			 String txt [] = {"Yes","No","Cancel"};
			 int result = JOptionPane.showOptionDialog(window, "Do you want to save the unsaved file?", "Unsaved work", 
		    		JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.WARNING_MESSAGE, null, txt, "Cancel");
			 switch (result)
			 {
			 case JOptionPane.YES_OPTION:
				 BasicActions.saveFile(window);
				 break;
			 case JOptionPane.NO_OPTION:
				 System.exit(0);
				 break;
			 case JOptionPane.CANCEL_OPTION:
				 break;
			 }
		   }
		   else
			   System.exit(0);
		  }	 
	}
	
	class ShortcutKeyListener implements KeyListener
	{
		Window window;
		
		ShortcutKeyListener(Window window_)
		{
			window=window_;
		}
		
		@Override
		public void keyTyped(KeyEvent e){}
		@Override
		public void keyReleased(KeyEvent e){}
		
		@Override
		public void keyPressed(KeyEvent e)
		{
			//If ctrl pressed:
			if ((e.getModifiers() & KeyEvent.CTRL_MASK) != 0)
				//Check if key is a shortcut:
				for (int i = 0; i < window.ctrlMenuShortcuts.length; ++i)
					if (e.getKeyCode() == window.ctrlMenuShortcuts[i])
						//Send corresponding string if shortcut found:
							window.evaluateMenuButton(window.menuItems[i]);
		}

	}
	
	class TextListener implements DocumentListener
	{

		@Override
		public void changedUpdate(DocumentEvent arg0)
		{
			setFileEdited(true);
		}

		@Override
		public void insertUpdate(DocumentEvent arg0)
		{
			setFileEdited(true);
		}

		@Override
		public void removeUpdate(DocumentEvent arg0)
		{
			setFileEdited(true);
		}
		
	}
	
	
	class Listener implements ActionListener
	{
		Window window;
		
		Listener(Window window)
		{
			this.window=window;
		}
		
		@Override
		public void actionPerformed(ActionEvent e)
		{
			String cm = e.getActionCommand();
			window.evaluateMenuButton(cm);
		}
		
	};
}