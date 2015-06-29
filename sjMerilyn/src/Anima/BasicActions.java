package Anima;
import java.awt.*;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

import javax.swing.*;

import sun.management.FileSystem;


class About extends JDialog
{
	private static final long serialVersionUID = 1L;

	About(Window window)
	{
		initUI(window);
	}
	
	public void initUI(Window window)
	{
		setModalityType(ModalityType.APPLICATION_MODAL);
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		setTitle("About");
		setSize(300,400);
		setLocationRelativeTo(window);
		
		setLayout(new BoxLayout(getContentPane(),BoxLayout.Y_AXIS));
		add(Box.createRigidArea(new Dimension(250,100)));
		JLabel text = new JLabel("~~~~~~~\nMerilyn\n~~~~~~~");
		text.setAlignmentX(0.5f);
		text.setFont(new Font("Serif",Font.BOLD,16));
		add(text);
	}
}

public class BasicActions
{
	static JFileChooser jfc = new JFileChooser();
	
public static void error(Window window, String message)
{
	JOptionPane.showMessageDialog(window, message);
}
	

public static boolean newFile(Window window)
{
	window.textarea.setText("");
	window.openedFilePath="null";
	window.openedFileName = "New File";
	window.setFileEdited(false);
	return true;
}

public static boolean saveFile(Window window)
{
	try
	{
		//If no open file
		if (window.openedFilePath.equals("null"))
		{
			return saveAsFile(window);
		}
		
		FileWriter rf = new FileWriter(window.openedFilePath);
		rf.write(window.textarea.getText());
		rf.close();
		window.setFileEdited(false);
	}
	catch (Exception e)
	{
		error(window,"Could not save file: " + e.getMessage());
		return false;
	}
	
	return true;
}

public static boolean saveAsFile(Window window)
{
	try
	{
		int result = jfc.showSaveDialog(window);
		if (result==1)
			return true; //Nothing selected
		File file = jfc.getSelectedFile();
		FileWriter rf = new FileWriter(file);
		rf.write(window.textarea.getText());
		rf.close();
		window.openedFilePath=file.getAbsolutePath();
		window.openedFileName=file.getName();
		window.setFileEdited(false);
	}
	catch (Exception e)
	{
		error(window,"Could not save file: " + e.getMessage());
		return false;
	}
	
	return true;
}

public static boolean openFile(Window window)
{
	try
	{
		int result = jfc.showOpenDialog(window);
		if (result==1)
			return true; //Nothing selected
		File file = jfc.getSelectedFile();
		Scanner scan = new Scanner(file);
		String content = scan.useDelimiter("\\Z").next();
		scan.close();
		window.textarea.setText(content);
		window.openedFilePath=file.getAbsolutePath();
		window.openedFileName = file.getName();
		window.setFileEdited(false);
	}
	catch (Exception e)
	{
		error(window,"Could not open file: " + e.getMessage());
		return false;
	}
	return true;
}

public static boolean about(Window window)
{
	About about = new About(window);
	about.setVisible(true);
	return true;
}

public static boolean copy(Window window)
{
	window.textarea.copy();
	return true;
}

public static boolean cut(Window window)
{
	window.textarea.cut();
	return true;
}

public static boolean paste(Window window)
{
	window.textarea.paste();
	return true;
}


}
