using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Loader
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("https://github.com/mvxxx");
        }

        private void linkLabel2_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("https://github.com/mvxxx/WireWorld");
        }

        private void TBa1_TextChanged(object sender, EventArgs e)
        {
            TBa2.Text = TBa1.Text;
        }

        private void TBa2_TextChanged(object sender, EventArgs e)
        {
            TBa1.Text = TBa2.Text;
        }

        private bool checkValueFromTBa()
        {
            int parsedValue;
            if (!int.TryParse(TBa1.Text, out parsedValue) || parsedValue < 1 || parsedValue > 100)
            {
                MessageBox.Show("You need to enter integer from <1;100> in ammount textboxes.");
                return false;
            }
            return true;
        }

        private void TBd1_TextChanged(object sender, EventArgs e)
        {
            TBd2.Text = TBd1.Text;
        }

        private void TBd2_TextChanged(object sender, EventArgs e)
        {
            TBd1.Text = TBd2.Text;
        }

        private bool checkValueFromTBd()
        {
            int parsedValue;
            if (!int.TryParse(TBd1.Text, out parsedValue) || parsedValue < 1 || parsedValue > 50)
            {
                MessageBox.Show("You need to enter integer from <1;50> in dimension textboxes.");
                return false;
            }
            return true;
        }

        

        private void button1_Click(object sender, EventArgs e)
        {
            

           if(checkValueFromTBa()&&checkValueFromTBd())
            {
                if (TBd1.Text == "" || TBa1.Text == "") MessageBox.Show("You need to fill all textboxes.");
                else if (TBs.Text == "") MessageBox.Show("Use scroll to enter a value of move speed");
                else
                {
                    try
                    {
                        File.WriteAllText("source/Loader/data/options.txt", "WireWorld" + Environment.NewLine + TBd1.Text + " " + TBd2.Text + Environment.NewLine + TBa1.Text + " " + TBa2.Text + Environment.NewLine + TBs.Text);
                        var game = new System.Diagnostics.Process();
                        game.StartInfo.FileName = "WireWorld.exe";
                        game.Start();
                        this.Close();
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show("An error occurred - please contact with author of project.");
                    }
                }
            } 
           
        }

        private void hScrollBar1_Scroll(object sender, ScrollEventArgs e)
        {
            TBs.Text = Convert.ToString(hScrollBar1.Value);
        }
    }
}
