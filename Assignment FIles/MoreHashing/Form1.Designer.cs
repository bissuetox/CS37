namespace MoreHashing
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.KeyTextBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.ValueTextBox = new System.Windows.Forms.TextBox();
            this.HashedItemsTextBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.AddUserInputButton = new System.Windows.Forms.Button();
            this.AddRandomInput = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.TableSizeLabel = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // KeyTextBox
            // 
            this.KeyTextBox.Location = new System.Drawing.Point(53, 12);
            this.KeyTextBox.Name = "KeyTextBox";
            this.KeyTextBox.Size = new System.Drawing.Size(65, 20);
            this.KeyTextBox.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(25, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Key";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 41);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(34, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Value";
            // 
            // ValueTextBox
            // 
            this.ValueTextBox.Location = new System.Drawing.Point(53, 38);
            this.ValueTextBox.Name = "ValueTextBox";
            this.ValueTextBox.Size = new System.Drawing.Size(65, 20);
            this.ValueTextBox.TabIndex = 2;
            // 
            // HashedItemsTextBox
            // 
            this.HashedItemsTextBox.Location = new System.Drawing.Point(212, 38);
            this.HashedItemsTextBox.Multiline = true;
            this.HashedItemsTextBox.Name = "HashedItemsTextBox";
            this.HashedItemsTextBox.Size = new System.Drawing.Size(222, 151);
            this.HashedItemsTextBox.TabIndex = 4;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(212, 19);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(32, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Items";
            // 
            // AddUserInputButton
            // 
            this.AddUserInputButton.Location = new System.Drawing.Point(19, 64);
            this.AddUserInputButton.Name = "AddUserInputButton";
            this.AddUserInputButton.Size = new System.Drawing.Size(75, 23);
            this.AddUserInputButton.TabIndex = 6;
            this.AddUserInputButton.Text = "Add";
            this.AddUserInputButton.UseVisualStyleBackColor = true;
            this.AddUserInputButton.Click += new System.EventHandler(this.AddUserInputButton_Click);
            // 
            // AddRandomInput
            // 
            this.AddRandomInput.Location = new System.Drawing.Point(19, 93);
            this.AddRandomInput.Name = "AddRandomInput";
            this.AddRandomInput.Size = new System.Drawing.Size(99, 23);
            this.AddRandomInput.TabIndex = 7;
            this.AddRandomInput.Text = "Add Random";
            this.AddRandomInput.UseVisualStyleBackColor = true;
            this.AddRandomInput.Click += new System.EventHandler(this.AddRandomInput_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(250, 19);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(57, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "Table Size";
            // 
            // TableSizeLabel
            // 
            this.TableSizeLabel.AutoSize = true;
            this.TableSizeLabel.Location = new System.Drawing.Point(313, 19);
            this.TableSizeLabel.Name = "TableSizeLabel";
            this.TableSizeLabel.Size = new System.Drawing.Size(0, 13);
            this.TableSizeLabel.TabIndex = 9;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(382, 19);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(0, 13);
            this.label5.TabIndex = 11;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(319, 19);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(57, 13);
            this.label6.TabIndex = 10;
            this.label6.Text = "Table Size";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(594, 262);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.TableSizeLabel);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.AddRandomInput);
            this.Controls.Add(this.AddUserInputButton);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.HashedItemsTextBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.ValueTextBox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.KeyTextBox);
            this.Name = "Form1";
            this.Text = "Hash Table";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox KeyTextBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox ValueTextBox;
        private System.Windows.Forms.TextBox HashedItemsTextBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button AddUserInputButton;
        private System.Windows.Forms.Button AddRandomInput;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label TableSizeLabel;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
    }
}

