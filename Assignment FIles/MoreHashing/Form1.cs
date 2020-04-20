using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MoreHashing
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        System.Collections.Hashtable hashedData = new System.Collections.Hashtable();
        private void AddUserInputButton_Click(object sender, EventArgs e)
        {
            AddToTable(this.KeyTextBox.Text, this.ValueTextBox.Text);
        }

        private void AddToTable(string key, string value)
        {
            try
            {
                hashedData.Add(key, value);
                TableSizeLabel.Text = hashedData.Count.ToString();
                DumpTableToTextBox();
            }
            catch (Exception ex)
            {
                MessageBox.Show("You cannot add duplicate keys!" + ex.Message, "Bad bad bad", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        Random rand = new Random();
        private void AddRandomInput_Click(object sender, EventArgs e)
        {
            string key = rand.Next(100).ToString();
            string value = DateTime.Now.ToShortTimeString();
            MessageBox.Show(String.Format("Adding key {0}, val {1}", key, value), "Data Added", MessageBoxButtons.OK, MessageBoxIcon.Information);
            AddToTable(key, value);
        }

        private void DumpTableToTextBox()
        {
            HashedItemsTextBox.Clear();
            foreach (object key in hashedData.Keys)
            {
                HashedItemsTextBox.AppendText(string.Format("Key: {0}, Value: {1}" + Environment.NewLine, 
                    key, hashedData[key]));
            }
        }
    }
}
